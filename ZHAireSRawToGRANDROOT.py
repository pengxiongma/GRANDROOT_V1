#!/usr/bin/python

import sys
import os
import glob
import logging
import numpy as np
from voltagecalculate import main_spectrum
#import h5py
logging.basicConfig(level=logging.DEBUG)
#
#you can get ZHAIRES python from https://github.com/mjtueros/ZHAireS-Python (checkout the Development or DevelopmentLeia branch)
#I use this environment variable to let python know where to find it, but alternatively you just copy the AiresInfoFunctions.py file on the same dir you are using this.
#ZHAIRESPYTHON=os.environ["ZHAIRESPYTHON"]
#sys.path.append(ZHAIRESPYTHON)
import AiresInfoFunctionsGRANDROOT as AiresInfo
import GRANDRoot 
import ROOT
from copy import deepcopy
import ComputeVoltageOnGRANDROOT as signal
from scipy.signal import hilbert
logging.basicConfig(level=logging.INFO)	
logging.getLogger('matplotlib').setLevel(logging.ERROR)

def ZHAiresRawToGRANDROOT(FileName, RunID, EventID, InputFolder, SimEfieldInfo=True, NLongitudinal=True, ELongitudinal=True, NlowLongitudinal=True, ElowLongitudinal=True, EdepLongitudinal=True, LateralDistribution=True, EnergyDistribution=True):
    '''
    This routine will read a ZHAireS simulation located in InputFlder and put it in the RootFileHandle. 
    RunID is the ID if the run is going to be associated with, which should be already on the existing on the file.
    EventID is the ID of the Event
    
    The function will write only the "Event section of the file. The Run section will be done in other function"
    
    '''
    #TODO: Think about RunID and EventID conventions. (data type, etc.)
	#TODO: Handle when RunID is invalid: The Run description should be in the file?
	#TODO: Handle when EventID is invalid: it must be unique 
	#      LWP: this is unhandlable on the ROOT level (files do not know about each other). Although, we could have a central database. Still, this would make making TTrees much more complicated (always need to query the db). 
	#      MJT: Oh, i was thinking at least only inside the file. To avoid creating the same twice.
	#TODO: Nice Feature: Get the next correlative EventID if none is specified 
	#      LWP: again, this requires some centralised mechanism of knowing the IDs. 
	#      MJT: Still thinking within the file.	
	#TODO: Think about reference frame. My gut is to put everything in the SimShower and SimEfield section in shower coordinate frame. 
	#      LWP: shouldn't it be in the Run then?. 
	#      MJT: No...im talking about what coordinate system to use in the file.
	# Becouse this is what was used in the input of the sims, and is what you would use if you want to
	#      re-process the event to, for example, move it to a different site. The coordinates of things in GP300 frame should be in the RawData section and beyond. And its easier.
	#      The conversion to "site frame" would be done at the RawEvent level or at the SimSignal level, the logic being that this requires more information than the simple input or output of ZHAIRES.

    logging.info("###")
    logging.info("###")
    logging.info("### Starting with event in "+ InputFolder+" to add in "+FileName) 
	
    #The function will write two main sections: ShowerSim and EfieldSim  . Shower Sim Can Optionale Store different tables.         
    SimShowerInfo=True
    SimEfieldInfo=True 
    ROOT.gInterpreter.ProcessLine('#include "./Event/SimEfield.h"')
    ROOT.gInterpreter.ProcessLine('#include "./Event/SimSignal.h"')
    ROOT.gInterpreter.ProcessLine('#include "./Event/SimShower.h"')

    #########################################################################################################
    #ZHAIRES Sanity Checks
    #########################################################################################################
    #TODO: Handle when InputFolder Does not exist, or is invalid (.sry,.idf and .trace files does not exist)
 
    idffile=glob.glob(InputFolder+"/*.idf")

    if(len(idffile)!=1 and (NLongitudinal or ELongitudinal or NlowLongitudinal or ElowLongitudinal or EdepLongitudinal or LateralDistribution or EnergyDistribution)):
        logging.critical("there should be one and only one idf file in the input directory!. cannot continue!")
        return -1

    sryfile=glob.glob(InputFolder+"/*.sry")

    if(len(sryfile)!=1):
        logging.critical("there should be one and only one sry file in the input directory!. cannot continue!")
        return -1

    EventName=AiresInfo.GetTaskNameFromSry(sryfile[0])

    inpfile=glob.glob(InputFolder+"/*.inp")
    if(len(inpfile)!=1):
        logging.critical("we can only get the core position from the input file, and it should be in the same directory as the sry")
        logging.critical("defaulting to (0.0,0)")
        inpfile=[None]
        CorePosition=(0.0,0.0,0.0)
	
	###########################################################################################################	
    #Root Sanity Checks  #TODO: Discuss with Lech: Should these be functions in GRANDRoot once its mature?  so its always done in the same way?
    ###########################################################################################################
    #TODO: Handle when FileName or RootFileHandle is invalid (does not exist, or is not writable, or whatever we decide is invalid (i.e. must already have the trees).)
    #TODO: Handle to check that SimShowerRun exist and the RunID is valid
    #TODO: these things should not be passed into this function as globals
    	    
    f = ROOT.TFile(FileName, "update")
    # No compresion for fast readout
    # TODO: LWP: decide on compression. ROOT uses some by default. Should we?
    #       MJT: if it is only setting a parameter, we can benchmark later
    f.SetCompressionLevel(1)
    
    # Check if the EventID is unique
    if not CheckIfEventIDIsUnique(EventID, f):
        print(f"The provided EventID {EventID} is not unique. Please provide a unique one.")
        return -1

    #############################################################################################################################
    # ShowerSimInfo (deals with the details for the simulation). This might be simulator-dependent (CoREAS has different parameters)
    #############################################################################################################################
    if(SimShowerInfo):
        #########################################################################################################################
        # Part 0: Set up the tree. #TODO: Discuss with Lech: Should this be all a function in GRANDRoot once its mature?  so its always done in the same way?
        #########################################################################################################################
        #TODO: Handle to check that SimShower exist and the RunID is valid
        create_branches = False
        # Try to get the tree from the file
        try:
          SimShower_tree = f.SimShowerTree
        # TTree doesnt exist - create it
        except:
          SimShower_tree = ROOT.TTree("SimShowerTree", "SimShowertree")
          create_branches = True
                  
        # Setup TTree branches for SimShower
        SimShower = GRANDRoot.Setup_SimShower_Branches(SimShower_tree, create_branches)
        #print("simshower branches", SimShower)

        #########################################################################################################################
        # Part I: get the information from ZHAIRES (for COREAS, its stuff would be here)
        #########################################################################################################################   
        #TODO: Check units are in GRAND conventions
        Primary= AiresInfo.GetPrimaryFromSry(sryfile[0],"GRAND")
        Zenith = AiresInfo.GetZenithAngleFromSry(sryfile[0],"GRAND")
        Azimuth = AiresInfo.GetAzimuthAngleFromSry(sryfile[0],"GRAND")
        Energy = AiresInfo.GetEnergyFromSry(sryfile[0],"GRAND")
        XmaxAltitude, XmaxDistance, XmaxX, XmaxY, XmaxZ = AiresInfo.GetKmXmaxFromSry(sryfile[0])
        #Convert to m
        XmaxAltitude= float(XmaxAltitude)*1000.0
        XmaxDistance= float(XmaxDistance)*1000.0
        XmaxPosition= [float(XmaxX)*1000.0, float(XmaxY)*1000.0, float(XmaxZ)*1000.0]
        SlantXmax=AiresInfo.GetSlantXmaxFromSry(sryfile[0])
        InjectionAltitude=AiresInfo.GetInjectionAltitudeFromSry(sryfile[0])

        #TODO: Add Injection Postion. On neutrino showers this is important (and there can be no Core position)		
        Lat,Long=AiresInfo.GetLatLongFromSry(sryfile[0])
        GroundAltitude=AiresInfo.GetGroundAltitudeFromSry(sryfile[0])
        Site=AiresInfo.GetSiteFromSry(sryfile[0])
        Date=AiresInfo.GetDateFromSry(sryfile[0])
        #TODO: Check units conform to GRAND convention. Think about coordinates
        FieldIntensity,FieldInclination,FieldDeclination=AiresInfo.GetMagneticFieldFromSry(sryfile[0])
        AtmosphericModel=AiresInfo.GetAtmosphericModelFromSry(sryfile[0])
        HadronicModel=AiresInfo.GetHadronicModelFromSry(sryfile[0])		
        EnergyInNeutrinos=AiresInfo.GetEnergyFractionInNeutrinosFromSry(sryfile[0])
        EnergyInNeutrinos=EnergyInNeutrinos*Energy
        ShowerSimulator=AiresInfo.GetAiresVersionFromSry(sryfile[0])
        ShowerSimulator="Aires "+ShowerSimulator
        RandomSeed=AiresInfo.GetRandomSeedFromSry(sryfile[0])
        CPUTime=AiresInfo.GetTotalCPUTimeFromSry(sryfile[0],"N/A")

        ##########################################################################################################################
        # Part I.1: Convert to GP300 coordinates (here is where customization comes, input specific conventions) (TODO) 
        ########################################################################################################################## 
        # I will asume X is local magnetic north. Azimuths and Zenith
        # for sites big enough, local magnetic north can change over the array? Do we need to care for this
        
        #TODO: Document how the core position needs to be stored in the .inp. 
        #TODO  Decide coordinate system (site specific): Maybe store lat/lon and altitude of origin of coordinates, and put a cartesian there?
        #      An incoming porblem is that zhaires on its simulations uses a fixed earth radius...so the simulation wont be 100% consistent with the "geoid" grand coordinates. 
        # LWP: we could use Earth-centered coordinates for everything: MJT: dont really know how to handle that. Still need all the coordinate handle machinery to be developed.

        if(inpfile[0]!=None):
            CorePosition=AiresInfo.GetCorePositionFromInp(inpfile[0])
        else:
            CorePosition=(0,0,0)  
        print("CorePosition:",CorePosition)

        #TODO: These are ZHAireS specific parameters. Other simulators wont have these parameters, and might have others. How to handle this?
        #Should we save the input and sry file inside the ROOT file? like a string? And parse simulation software specific parameters from there?
        # LWP: perhaps we should have a separate tree for universal simulator parameters (that would not exist for a real experiment) and specific trees for specific simulators? But then we can forget about automatic parsing of such non-universal ttree. Perhaps some longish string in the universal simulator tree, to be parsed if anyone wants and knows how to, would be better?
        RelativeThinning=AiresInfo.GetThinningRelativeEnergyFromSry(sryfile[0])
        WeightFactor=AiresInfo.GetWeightFactorFromSry(sryfile[0])
        GammaEnergyCut=AiresInfo.GetGammaEnergyCutFromSry(sryfile[0])
        ElectronEnergyCut=AiresInfo.GetElectronEnergyCutFromSry(sryfile[0])
        MuonEnergyCut=AiresInfo.GetMuonEnergyCutFromSry(sryfile[0])
        MesonEnergyCut=AiresInfo.GetMesonEnergyCutFromSry(sryfile[0])
        NucleonEnergyCut=AiresInfo.GetNucleonEnergyCutFromSry(sryfile[0])


        ############################################################################################################################# 
        # Part II: Fill SimShower TTree	#TODO: Discuss with Lech: Should this be all a function in GRANDRoot once its mature? to hide all pushback and all those things? And so other people do the same?
        ############################################################################################################################  
        #SimShower['run_id'][:]=RunID
        #SimShower['evt_id'][:]=EventID
        #SimShower['shower_type'].push_back(str(Primary))       #TODO: Support multiple primaries (use a ROOT.Vector, like for the trace)
        #SimShower['shower_energy'][:]=Energy
        #SimShower['shower_azimuth'][:]=Azimuth
        #SimShower['shower_zenith'][:]=Zenith
        ##TODO:shower_core_pos
        #SimShower['rnd_seed'][:]=RandomSeed
        #SimShower['energy_in_neutrinos'][:]=EnergyInNeutrinos
        #SimShower['atmos_model'].push_back(AtmosphericModel)
        ##TODO:atmos_model_param
        #SimShower['magnetic_field'][:]=np.array([FieldInclination,FieldDeclination,FieldIntensity])
        #SimShower['date'].push_back(Date)
        #SimShower['site'].push_back(Site)
        #SimShower['site_lat_long'][:]=np.array([Lat,Long])
        #SimShower['ground_alt'][:]=GroundAltitude
        #SimShower['prim_energy'][:]=Energy
        #SimShower['prim_type'].push_back(str(Primary))
        ##TODO prim_injpoint_shc						
        #SimShower['prim_inj_alt_shc'][:]=InjectionAltitude
        ##TODO:prim_inj_dir_shc
        #SimShower['xmax_grams'][:]=SlantXmax
        #SimShower['xmax_alt'][:]=XmaxAltitude
        ##TODO:gh_fit_param
        #SimShower['xmax_pos_shc'][:]=np.array([float(XmaxX)*1000,float(XmaxY)*1000,float(XmaxZ)*1000])
        #SimShower['hadronic_model'].push_back(HadronicModel)
        ##TODO:low_energy_model
        #SimShower['cpu_time'][:]=CPUTime
        
        print("Filling SimShower")

#        SimShower_tree.Fill()  #TODO:we might want to sumbit all the Fill Commands (or at least the Write comands) together at the end to ensure we write down to file complete records. # LWP: no problem for both. Also, there are options like AutoSave() etc., for writing, which we should consider
#        SimShower_tree.SetTreeIndex(ROOT.nullptr)
#        SimShower_tree.BuildIndex("run_id", "evt_id")
#        SimShower_tree.Write("", ROOT.TObject.kWriteDelete)

    #############################################################################################################################
    #	SimEfieldInfo
    #############################################################################################################################
    
    #ZHAIRES DEPENDENT
    #ending_e = "/a*.trace"
    #ending_e = "/VoltageADC_Dec2A*.trace"
    #ending_e = "/voc_a*_trace.txt"
    #ending_e = "/vlna_a*_trace.txt"
    ending_e = "/vfilter_a*_trace.txt"
    tracefiles=glob.glob(InputFolder+ending_e)

    if(SimEfieldInfo and len(tracefiles)>0):
        #########################################################################################################################
        # Part 0: Set up the tree TODO: Discuss with Lech: Should these be functions in GRANDRoot once its mature? 
        #########################################################################################################################		
        #TODO: Handle to check that SimEfield exist and the RunID is valid
        create_branches = False
        #Try to get the tree from the file
        try:
          SimEfield_tree = f.SimEfieldTree
        except:
          SimEfield_tree = ROOT.TTree("SimEfieldTree", "SimEfieldtree")
          create_branches = True

        SimEfieldBr=ROOT.SimEfield()
        SimSignalBr=ROOT.SimSignal()
        SimShowerBr=ROOT.SimShower()
        try:
            SimuTree =   f.SimuCollection
            EfieldTree = f.EfieldCollection
            SignalTree = f.SignalCollection
            SimuTree.SetBranchAddress("SimShowerBranch", SimShowerBr)
            EfieldTree.SetBranchAddress("SimEfieldBranch", SimEfieldBr)
            SignalTree.SetBranchAddress("SimSignalBranch", SimSignalBr)
        except:
            SimuTree = ROOT.TTree("SimuCollection", "SimuCollection")
            EfieldTree = ROOT.TTree("EfieldCollection", "EfieldCollection")
            SignalTree = ROOT.TTree("SignalCollection", "SignalCollection")
            #SimuTree.Branch("SimEfield", ROOT.addressof(SimEfieldBr,"SimEfield"), "SimEfield/C")
            #SimuTree.Branch("SimSignal", ROOT.addressof(SimSignalBr, "SimSignal"), "SimSignal/C")
            SimuTree.Branch("SimShowerBranch", SimShowerBr)
            EfieldTree.Branch("SimEfieldBranch", SimEfieldBr)
            SignalTree.Branch("SimSignalBranch", SimSignalBr)
        #SimEfieldBr.run_id=0
    
      
        print(SimuTree.GetName())
        #Create TTree branches for Sim Efield
        SimEfield=GRANDRoot.Setup_SimEfield_Branches(SimEfield_tree,create_branches)
        SimEfield_Detector=GRANDRoot.Setup_SimEfieldDetector_Branches(SimEfield_tree,create_branches)      #TODO: Decide if this goes in a separate tree, or is kept inside SimEfield
                  
	    #########################################################################################################################
        # Part I: get the information
        #########################################################################################################################  	
        #TODO: Get Refractivity Model parameters from the sry

        #Getting all the information i need for	SimEfield
        FieldSimulator=AiresInfo.GetZHAireSVersionFromSry(sryfile[0])
        FieldSimulator="ZHAireS "+str(FieldSimulator)
        RefractionIndexModel="Exponential" #TODO: UNHARDCODE THIS
        RefractionIndexParameters=[1.0003250,-0.1218] #TODO: UNHARDCODE THIS
        print("Warning, hard coded RefractionIndexModel",RefractionIndexModel,RefractionIndexParameters)
        #
        TimeBinSize=AiresInfo.GetTimeBinFromSry(sryfile[0])
        TimeWindowMin=AiresInfo.GetTimeWindowMinFromSry(sryfile[0])
        TimeWindowMax=AiresInfo.GetTimeWindowMaxFromSry(sryfile[0])

        #TODO:Add magnetic field information 

        ##########################################################################################################################
        # Part I.1: Convert to GP300 coordinates (here is where customization comes, input specific conventions) (TODO) 
        ##########################################################################################################################
        #Here Magnetic field might need to be converted to GRAND coordinates       

        ############################################################################################################################# 
        # Part II: Fill SimEfield TTree	
        ############################################################################################################################ 
        #Populate what we can
        SimEfield['run_id'][:]=int(RunID)
        SimEfield['evt_id'][:]=int(EventID)
        SimEfield['field_sim'].push_back(FieldSimulator)                #TODO: Decide if this goes into the SimEfieldRun Info
        print(SimEfield['field_sim'])
        SimEfield['refractivity_model'].push_back(RefractionIndexModel) #TODO: Decide if this goes into the SimEfieldRun Info
        SimEfield['refractivity_param'][:]=RefractionIndexParameters    #TODO: Decide if this goes into the SimEfieldRun Info. If we want to support time or location differences in the index of refraction...probabbly keep it here
        SimEfield['t_pre'][:]=TimeWindowMin                             #TODO: Decide if this goes into the SimEfieldRun Info
        SimEfield['t_post'][:]=TimeWindowMax                            #TODO: Decide if this goes into the SimEfieldRun Info  
        SimEfield['t_bin_size'][:]=TimeBinSize                          #TODO: Decide if this goes into the SimEfieldRun Info . If we want to support sims with different trace sizes, this must go here. It might be needed, its difficult (and/or inefficient) to treat all traces as the same lenght. Trace lenght depends on geometry     

        print("RUN ID:.......", type(RunID), RunID)
        SimEfieldBr.run_id = RunID
        SimEfieldBr.evt_id = EventID        
        SimEfieldBr.field_sim.push_back(FieldSimulator)                #TODO: Decide if this goes into the SimEfieldRun Info
        #SimEfieldBr.refractivity_model.push_back(RefractionIndexModel) #TODO: Decide if this goes into the SimEfieldRun Info
        SimEfieldBr.refractivity_param1=float(RefractionIndexParameters[0])    #TODO: Decide if this goes into the SimEfieldRun Info. If we want to support time or location differences in the index of refraction...probabbly keep it here
        SimEfieldBr.refractivity_param2=float(RefractionIndexParameters[1])    #TODO: Decide if this goes into the SimEfieldRun Info. If we want to support time or location differences in the index of refraction...probabbly keep it here
        #SimEfieldBr.refractivity_param[1]= float(RefractionIndexParameters[1])    #TODO: Decide if this goes into the SimEfieldRun Info. If we want to support time or location differences in the index of refraction...probabbly keep it here
        SimEfieldBr.t_pre=TimeWindowMin                             #TODO: Decide if this goes into the SimEfieldRun Info
        SimEfieldBr.t_post=TimeWindowMax                            #TODO: Decide if this goes into the SimEfieldRun Info  
        SimEfieldBr.t_bin_size=TimeBinSize                          #TODO: Decide if this goes into the SimEfieldRun Info . If we want to support sims with different trace sizes, this must go here. It might be needed, its difficult (and/or inefficient) to treat all traces as the same lenght. Trace lenght depends on geometry     
        print("SimEfield Branch:", SimEfieldBr.run_id, SimEfieldBr.evt_id, \
              RefractionIndexParameters,
              SimEfieldBr.field_sim,  SimEfieldBr.refractivity_model, SimEfieldBr.refractivity_param1,\
              SimEfieldBr.t_pre, SimEfieldBr.t_post, SimEfieldBr.t_bin_size)
        
        SimShowerBr.run_id=int(RunID)
        SimShowerBr.evt_id=int(EventID)
        SimShowerBr.shower_type.push_back(str(Primary))       #TODO: Support multiple primaries (use a ROOT.Vector, like for the trace)
        SimShowerBr.shower_energy=Energy
        SimShowerBr.shower_azimuth=Azimuth
        SimShowerBr.shower_zenith=Zenith
        #TODO:shower_core_pos
        SimShowerBr.rnd_seed=float(RandomSeed)
        SimShowerBr.energy_in_neutrinos=float(EnergyInNeutrinos)
        SimShowerBr.atmos_model.push_back(AtmosphericModel)
        #TODO:atmos_model_param
        SimShowerBr.magnetic_field.push_back(FieldInclination)
        SimShowerBr.magnetic_field.push_back(FieldDeclination)
        SimShowerBr.magnetic_field.push_back(FieldIntensity)
        SimShowerBr.date.push_back(Date)
        SimShowerBr.site.push_back(Site)
        SimShowerBr.site_lat_long.push_back(float(Lat))
        SimShowerBr.site_lat_long.push_back(float(Long))
        SimShowerBr.ground_alt=GroundAltitude
        SimShowerBr.prim_energy=Energy
        SimShowerBr.prim_type.push_back(str(Primary))
        #TODO prim_injpoint_shc						
        SimShowerBr.prim_inj_alt_shc=InjectionAltitude
        #TODO:prim_inj_dir_shc
        SimShowerBr.xmax_grams=float(SlantXmax)
        SimShowerBr.xmax_alt=float(XmaxAltitude)
        #SimShowerBr.xmax_pos_shc = [float(XmaxX)*1000,float(XmaxY)*1000,float(XmaxZ)*1000]
        SimShowerBr.xmax_pos_shc.push_back(XmaxX*1000)
        SimShowerBr.xmax_pos_shc.push_back(XmaxY*1000)
        SimShowerBr.xmax_pos_shc.push_back(XmaxZ*1000)
        #TODO:gh_fit_param
        SimShowerBr.hadronic_model.push_back(HadronicModel)
        #TODO:low_energy_model
        SimShowerBr.cpu_time.push_back(CPUTime)

 
        ############################################################################################################################# 
        # Fill SimEfield Detector part
        ############################################################################################################################ 
	    #########################################################################################################################
        # Part I: get the information
        ######################################################################################################################### 
        IDs,antx,anty,antz,antt=AiresInfo.GetAntennaInfoFromSry(sryfile[0])
 
        if(IDs[0]==-1 and antx[0]==-1 and anty[0]==-1 and antz[0]==-1 and antt[0]==-1):
	         logging.critical("hey, no antennas found in event sry "+ str(EventID)+" SimEfield not produced")         #TODO: handle this exeption more elegantly

        else:		

            #convert to 32 bits so it takes less space 
            antx=np.array(antx, dtype=np.float32)
            anty=np.array(anty, dtype=np.float32)
            antz=np.array(antz, dtype=np.float32)
            antt=np.array(antt, dtype=np.float32)
            #
   
           # Important remark. If we need to take into account round earth, then we will need to rotate the electric field components to go to a cartesian frame centered in the array                
            #TODO: check that the number of trace files found is coincidient with the number of antennas found from the sry  
            logging.info("found "+str(len(tracefiles))+" antenna trace files") 

            for ant in tracefiles:
                #print("into antenna", ant)
                #ant_number = int(ant.split('/')[-1].split('.trace')[0].split('a')[-1]) # index in selected antenna list. this only works if all antenna files are consecutive
                #ant_number = int(ant.split('/')[-1].split('.trace')[0].split('A')[-1]) # index in selected antenna list. this only works if all antenna files are consecutive
                ant_number = int(ant.split('/')[-1].split('_trace')[0].split('a')[-1]) # index in selected antenna list. this only works if all antenna files are consecutive
                
                #strsplit = ant.split('_')
                #etheta, ephi = [float(v) for v in strsplit[-3:-1]]
                #newvoltage = main_spectrum.main(etheta,ephi,ant,"")                                                                       # TODO: Check for this, and handle what hapens if it fails. Maybe there is a more elegant solution 

                #print("newvoltage ",newvoltage[1],newvoltage[2],newvoltage[3])
                
                DetectorID = ant_number                                                # TODO: set on what is detector ID. int? str?
                ant_position=(antx[ant_number],anty[ant_number],antz[ant_number])

                #efield = np.loadtxt(ant,dtype='f4') #we read the electric field as a numpy array
                efield = np.loadtxt(ant) #we read the electric field as a numpy array

                 
                ##########################################################################################################################
                # Part I.1: Convert to GP300 coordinates (here is where customization comes, input specific conventions) (TODO) 
                ##########################################################################################################################
                #TODO: Important remark. If we need to take into account round earth, then we will need to rotate the electric field components to go to a cartesian frame centered in the array
                #this needs to be provided by grandlib

                ############################################################################################################################# 
                # Part II: Fill SimEfield Detector	TODO: Discuss with Lech: Should these be functions in GRANDRoot once its mature? 
                ############################################################################################################################ 
                #Populate what we can                
                #SimEfield_Detector['det_id'].push_back(DetectorID)                
                SimEfieldBr.Detectors_det_id.push_back(DetectorID)                
                #
                tmp_v = ROOT.vector("float")()
                tmp_v.assign(ant_position)                                
                SimEfield_Detector['det_pos_shc'].push_back(tmp_v)          #TODO: Why is tmp_v needed? cant we do push_back(tuple(antposition))?
                SimEfieldBr.Detectors_det_pos_shc.push_back(tmp_v)          #TODO: Why is tmp_v needed? cant we do push_back(tuple(antposition))?
                #   
                tmp_v = ROOT.vector("string")()
                tmp_v.push_back("ZHAireS")                                     #TODO: Set this correctly
                SimEfield_Detector['det_type'].push_back(tmp_v)
                SimEfieldBr.Detectors_det_type.push_back(tmp_v)
                #
                t0=antt[ant_number]                 
                SimEfield_Detector['t_0'].push_back(t0)
                SimEfieldBr.Detectors_t_0.push_back(t0)
                #
                #trace: TODO: this could be condenced into one line, but it needs to be benchmarked SimEfield_Detector['trace_x'].push_back(ROOT.vector("float")(efield[:,1]))
                #
                efieldx=deepcopy(efield[:,1])
                efieldx=np.array(efieldx, dtype=np.float32)
                tmp_trace_x  = ROOT.vector("float")()
                tmp_trace_x.assign(efieldx)
                #SimEfield_Detector['trace_x'].push_back(tmp_trace_x)
                #
                efieldy=deepcopy(efield[:,2])
                efieldy=np.array(efieldy, dtype=np.float32)
                tmp_trace_y  = ROOT.vector("float")()
                tmp_trace_y.assign(efieldy)
                #SimEfield_Detector['trace_y'].push_back(tmp_trace_y)
                #
                efieldz=deepcopy(efield[:,3])
                efieldz=np.array(efieldz, dtype=np.float32)
                tmp_trace_z  = ROOT.vector("float")()
                tmp_trace_z.assign(efieldz)
                #SimEfield_Detector['trace_z'].push_back(tmp_trace_z)
                SimEfieldBr.Detectors_trace_x.push_back(tmp_trace_x)
                SimEfieldBr.Detectors_trace_y.push_back(tmp_trace_y)
                SimEfieldBr.Detectors_trace_z.push_back(tmp_trace_z)

                Eenvelopex = hilbert(efieldx)
                Eenvelopey = hilbert(efieldy)
                Eenvelopez = hilbert(efieldz)
                Emax = (Eenvelopex)**2;
                Emax = Emax + (Eenvelopey)**2
                Emax = Emax + (Eenvelopez)**2
                Emax2 = np.sqrt(Emax)
                emax = np.max(Emax2)
                emin = np.min(Emax2)
                exp2p = emax - emin
                Xemax = np.max(Eenvelopex)
                Xemin = np.min(Eenvelopex)
                Xexp2p = Xemax - Xemin
                Yemax = np.max(Eenvelopey)
                Yemin = np.min(Eenvelopey)
                Yexp2p = Yemax - Yemin
                Zemax = np.max(Eenvelopez)
                Zemin = np.min(Eenvelopez)
                Zexp2p = Zemax - Zemin
                #SimEfield_Detector['p2p'].push_back(exp2p)
                SimEfieldBr.Detectors_p2p.push_back(exp2p)
                SimEfieldBr.Detectors_p2p_x.push_back(Xexp2p)
                SimEfieldBr.Detectors_p2p_y.push_back(Yexp2p)
                SimEfieldBr.Detectors_p2p_z.push_back(Zexp2p)



                #tmp_trace  = ROOT.vector("TVector3")()
                #for x,y,z in zip(efieldx, efieldy, efieldz):
                #    vt = ROOT.TVector3(x,y,z)
                #    tmp_trace.push_back(vt)
                #SimEfieldBr.Detectors_trace.push_back(tmp_trace)

                tpre, tpost, tbinsize = TimeWindowMin, TimeWindowMax, TimeBinSize
                efield=np.column_stack((efieldx,efieldy,efieldz))
                times = np.arange(tpre+t0,tpost+t0+10*tbinsize,tbinsize,)
                times = times[0:np.shape(efield)[0]]
                efield=np.column_stack((times,efield))

                SimSignalBr.run_id=int(RunID)
                SimSignalBr.evt_id=int(EventID)
                SignalSimulator="CompuetVoltageOnGRANDROOT"                     
                SimSignalBr.signal_sim.push_back(SignalSimulator)
                SimSignalBr.Detectors_det_id.push_back(DetectorID)
                tmp_v = ROOT.vector("string")()
                tmp_v.push_back("ZHAireS")                                     #TODO: Set this correctly
                SimSignalBr.Detectors_det_type.push_back(tmp_v)
                tmp_v = ROOT.vector("float")()
                tmp_v.assign(ant_position)                                
                SimSignalBr.Detectors_det_pos_shc.push_back(tmp_v)
                SimSignalBr.Detectors_t_0.push_back(t0)
                fs=1e9/tbinsize #in Hz
                nu_low=1e9*0.03   #in Hz
                nu_high=1e9*0.3   #in Hz
                ###voltagex= signal.butter_bandpass_filter(efieldx,nu_low,nu_high,fs)
                ###voltagey= signal.butter_bandpass_filter(efieldy,nu_low,nu_high,fs)
                ###voltagez= signal.butter_bandpass_filter(efieldz,nu_low,nu_high,fs)
                ###voltagex=np.array(voltagex, dtype=np.float32)
                ###voltagey=np.array(voltagey, dtype=np.float32)
                ###voltagez=np.array(voltagez, dtype=np.float32)
                ###tmp_vtrace_x  = ROOT.vector("float")()
                ###tmp_vtrace_x.assign(voltagex)
                ###tmp_vtrace_y  = ROOT.vector("float")()
                ###tmp_vtrace_y.assign(voltagey)
                ###tmp_vtrace_z  = ROOT.vector("float")()
                ###tmp_vtrace_z.assign(voltagez)
                ###SimSignalBr.Detectors_trace_x.push_back(tmp_vtrace_x)
                ###SimSignalBr.Detectors_trace_y.push_back(tmp_vtrace_y)
                ###SimSignalBr.Detectors_trace_z.push_back(tmp_vtrace_z)
                ###SimSignalBr.Detectors_det_id.push_back(DetectorID)                
                
                #newvoltagex=deepcopy(newvoltage[1])
                #newvoltagey=deepcopy(newvoltage[2])
                #newvoltagez=deepcopy(newvoltage[3])
                #tmp_adc_x  = ROOT.vector("float")()
                #tmp_adc_x.assign(newvoltagex)
                #tmp_adc_y  = ROOT.vector("float")()
                #tmp_adc_y.assign(newvoltagey)
                #tmp_adc_z  = ROOT.vector("float")()
                #tmp_adc_z.assign(newvoltagez)
                #SimSignalBr.Voltage_trace_x.push_back(tmp_adc_x)
                #SimSignalBr.Voltage_trace_y.push_back(tmp_adc_y)
                #SimSignalBr.Voltage_trace_z.push_back(tmp_adc_z)
                
                ###Venvelopex = hilbert(voltagex)
                ###Venvelopey = hilbert(voltagey)
                ###Venvelopez = hilbert(voltagez)
                ###Vmax=(Venvelopex)**2;
                ###Vmax = Vmax + (Venvelopey)**2
                ###Vmax = Vmax + (Venvelopez)**2
                ###Vmax2 = np.sqrt(Vmax)
                ###emax=np.max(Vmax2)
                ###emin=np.min(Vmax2)
                ###exp2p=emax-emin
                ###SimSignalBr.Detectors_p2p.push_back(exp2p)
                ###SimSignalBr.Detectors_t_0.push_back(t0)

#                for x,y,z in zip(voltagex, voltagey, voltagez):
#                    vt = ROOT.TVector3(x,y,z)
#                    tmp_trace_vol.push_back(vt)
#                SimSignalBr.Detectors_trace.push_back(tmp_trace_vol)



                

                #TODO: Fill p2p and hilbert amplitudes
                #print("end anenna",ant_number)
            print("Saving SimEfield")    
            #print((SimEfieldBr.Detectors_trace)[0][0].X())
            #SimEfield_tree.Fill()
            ##This is to remove the friend if it exists before
            #SimEfield_tree.RemoveFriend(SimShower_tree)
            #SimEfield_tree.SetTreeIndex(ROOT.nullptr)
            #SimEfield_tree.BuildIndex("run_id", "evt_id")
            ## Need to remove the friend first - it was stored along the TTree in the previous Write() - otherwise AddFriend() crashes
            #SimEfield_tree.AddFriend(SimShower_tree)
            #SimEfield_tree.Write("", ROOT.TObject.kWriteDelete) #this is to avoid having several copies of the tree in the index of the file

            SimuTree.Fill()
            EfieldTree.Fill()
            SignalTree.Fill()
            SimuTree.Write("", ROOT.TObject.kWriteDelete)
            EfieldTree.Write("", ROOT.TObject.kWriteDelete)
            SignalTree.Write("", ROOT.TObject.kWriteDelete)



    else:
        logging.critical("no trace files found in "+InputFolder+"Skipping SimEfield") #TODO: handle this exeption more elegantl
    
	##############################################################################################################################
	# LONGITUDINAL TABLES (not implemented yet, will need to have ZHAIRES installed on your system and the Official version of AiresInfoFunctions)
	##############################################################################################################################

    if(NLongitudinal):
        #the gammas table
        table=AiresInfo.GetLongitudinalTable(InputFolder,1001,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteSlantDepth(HDF5handle, RunID, EventID, table.T[0])
        SimShower.SimShowerWriteNgammas(HDF5handle, RunID, EventID, table.T[1])

        #the eplusminus table, in vertical, to store also the vertical depth
        table=AiresInfo.GetLongitudinalTable(InputFolder,1205,Slant=False,Precision="Simple")
        SimShower.SimShowerWriteVerticalDepth(HDF5handle, RunID, EventID, table.T[0])
        SimShower.SimShowerWriteNeplusminus(HDF5handle, RunID, EventID, table.T[1])

        #the e plus (yes, the positrons)
        table=AiresInfo.GetLongitudinalTable(InputFolder,1006,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteNeplus(HDF5handle, RunID, EventID, table.T[1])

        #the mu plus mu minus
        table=AiresInfo.GetLongitudinalTable(InputFolder,1207,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteNmuplusminus(HDF5handle, RunID, EventID, table.T[1])

        #the mu plus
        table=AiresInfo.GetLongitudinalTable(InputFolder,1007,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteNmuplus(HDF5handle, RunID, EventID, table.T[1])

        #the pi plus pi munus
        table=AiresInfo.GetLongitudinalTable(InputFolder,1211,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteNpiplusminus(HDF5handle, RunID, EventID, table.T[1])

        #the pi plus
        table=AiresInfo.GetLongitudinalTable(InputFolder,1011,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteNpiplus(HDF5handle, RunID, EventID, table.T[1])

        #and the all charged
        table=AiresInfo.GetLongitudinalTable(InputFolder,1291,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteNallcharged(HDF5handle, RunID, EventID, table.T[1])

	##############################################################################################################################
	# Energy LONGITUDINAL TABLES (very important to veryfy the energy balance of the cascade, and to compute the invisible energy)
	##############################################################################################################################
    if(ELongitudinal):
        #the gammas
        table=AiresInfo.GetLongitudinalTable(InputFolder,1501,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteEgammas(HDF5handle, RunID, EventID, table.T[1])

        #i call the eplusminus table, in vertical, to store also the vertical depth
        table=AiresInfo.GetLongitudinalTable(InputFolder,1705,Slant=False,Precision="Simple")
        SimShower.SimShowerWriteEeplusminus(HDF5handle, RunID, EventID, table.T[1])

        #the mu plus mu minus
        table=AiresInfo.GetLongitudinalTable(InputFolder,1707,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteEmuplusminus(HDF5handle, RunID, EventID, table.T[1])

        #the pi plus pi minus
        table=AiresInfo.GetLongitudinalTable(InputFolder,1711,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteEpiplusminus(HDF5handle, RunID, EventID, table.T[1])

        #the k plus k minus
        table=AiresInfo.GetLongitudinalTable(InputFolder,1713,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteEkplusminus(HDF5handle, RunID, EventID, table.T[1])

        #the neutrons
        table=AiresInfo.GetLongitudinalTable(InputFolder,1521,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteEneutrons(HDF5handle, RunID, EventID, table.T[1])

        #the protons
        table=AiresInfo.GetLongitudinalTable(InputFolder,1522,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteEprotons(HDF5handle, RunID, EventID, table.T[1])

        #the anti-protons
        table=AiresInfo.GetLongitudinalTable(InputFolder,1523,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteEpbar(HDF5handle, RunID, EventID, table.T[1])

        #the nuclei
        table=AiresInfo.GetLongitudinalTable(InputFolder,1541,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteEnuclei(HDF5handle, RunID, EventID, table.T[1])

        #the other charged
        table=AiresInfo.GetLongitudinalTable(InputFolder,1591,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteEother_charged(HDF5handle, RunID, EventID, table.T[1])

        #the other neutral
        table=AiresInfo.GetLongitudinalTable(InputFolder,1592,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteEother_neutral(HDF5handle, RunID, EventID, table.T[1])

        #and the all
        table=AiresInfo.GetLongitudinalTable(InputFolder,1793,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteEall(HDF5handle, RunID, EventID, table.T[1])

    ################################################################################################################################
    # NLowEnergy Longitudinal development
    #################################################################################################################################
    if(NlowLongitudinal):
        #the gammas
        table=AiresInfo.GetLongitudinalTable(InputFolder,7001,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteNlowgammas(HDF5handle, RunID, EventID, table.T[1])

        #i call the eplusminus table, in vertical, to store also the vertical depth
        table=AiresInfo.GetLongitudinalTable(InputFolder,7005,Slant=False,Precision="Simple")
        SimShower.SimShowerWriteNloweplusminus(HDF5handle, RunID, EventID, table.T[1])

        #the positrons (note that they will deposit twice their rest mass!)
        table=AiresInfo.GetLongitudinalTable(InputFolder,7006,Slant=False,Precision="Simple")
        SimShower.SimShowerWriteNloweplus(HDF5handle, RunID, EventID, table.T[1])

        #the muons
        table=AiresInfo.GetLongitudinalTable(InputFolder,7207,Slant=False,Precision="Simple")
        SimShower.SimShowerWriteNlowmuons(HDF5handle, RunID, EventID, table.T[1])

        #Other Chaged
        table=AiresInfo.GetLongitudinalTable(InputFolder,7091,Slant=False,Precision="Simple")
        SimShower.SimShowerWriteNlowother_charged(HDF5handle, RunID, EventID, table.T[1])

        #Other Neutral
        table=AiresInfo.GetLongitudinalTable(InputFolder,7092,Slant=False,Precision="Simple")
        SimShower.SimShowerWriteNlowother_neutral(HDF5handle, RunID, EventID, table.T[1])

    ################################################################################################################################
    # ELowEnergy Longitudinal development
    #################################################################################################################################
    if(ElowLongitudinal):
        #the gammas
        table=AiresInfo.GetLongitudinalTable(InputFolder,7501,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteElowgammas(HDF5handle, RunID, EventID, table.T[1])

        #i call the eplusminus table, in vertical, to store also the vertical depth
        table=AiresInfo.GetLongitudinalTable(InputFolder,7505,Slant=False,Precision="Simple")
        SimShower.SimShowerWriteEloweplusminus(HDF5handle, RunID, EventID, table.T[1])

        #the positrons (note that they will deposit twice their rest mass!)
        table=AiresInfo.GetLongitudinalTable(InputFolder,7506,Slant=False,Precision="Simple")
        SimShower.SimShowerWriteEloweplus(HDF5handle, RunID, EventID, table.T[1])

        #the muons
        table=AiresInfo.GetLongitudinalTable(InputFolder,7707,Slant=False,Precision="Simple")
        SimShower.SimShowerWriteElowmuons(HDF5handle, RunID, EventID, table.T[1])

        #Other Chaged
        table=AiresInfo.GetLongitudinalTable(InputFolder,7591,Slant=False,Precision="Simple")
        SimShower.SimShowerWriteElowother_charged(HDF5handle, RunID, EventID, table.T[1])

        #Other Neutral
        table=AiresInfo.GetLongitudinalTable(InputFolder,7592,Slant=False,Precision="Simple")
        SimShower.SimShowerWriteElowother_neutral(HDF5handle, RunID, EventID, table.T[1])

    ################################################################################################################################
    # EnergyDeposit Longitudinal development
    #################################################################################################################################
    if(EdepLongitudinal):
        #the gammas
        table=AiresInfo.GetLongitudinalTable(InputFolder,7801,Slant=True,Precision="Simple")
        SimShower.SimShowerWriteEdepgammas(HDF5handle, RunID, EventID, table.T[1])

        #i call the eplusminus table, in vertical, to store also the vertical depth
        table=AiresInfo.GetLongitudinalTable(InputFolder,7805,Slant=False,Precision="Simple")
        SimShower.SimShowerWriteEdepeplusminus(HDF5handle, RunID, EventID, table.T[1])

        #the positrons (note that they will deposit twice their rest mass!)
        table=AiresInfo.GetLongitudinalTable(InputFolder,7806,Slant=False,Precision="Simple")
        SimShower.SimShowerWriteEdepeplus(HDF5handle, RunID, EventID, table.T[1])

        #the muons
        table=AiresInfo.GetLongitudinalTable(InputFolder,7907,Slant=False,Precision="Simple")
        SimShower.SimShowerWriteEdepmuons(HDF5handle, RunID, EventID, table.T[1])

        #Other Chaged
        table=AiresInfo.GetLongitudinalTable(InputFolder,7891,Slant=False,Precision="Simple")
        SimShower.SimShowerWriteEdepother_charged(HDF5handle, RunID, EventID, table.T[1])

        #Other Neutral
        table=AiresInfo.GetLongitudinalTable(InputFolder,7892,Slant=False,Precision="Simple")
        SimShower.SimShowerWriteEdepother_neutral(HDF5handle, RunID, EventID, table.T[1])

    ################################################################################################################################
    # Lateral Tables
    #################################################################################################################################
    if(LateralDistribution):
        #the gammas
        table=AiresInfo.GetLateralTable(InputFolder,2001,Density=False,Precision="Simple")
        SimShower.SimShowerWriteLDFradius(HDF5handle, RunID, EventID, table.T[0])
        SimShower.SimShowerWriteLDFgamma(HDF5handle, RunID, EventID, table.T[1])

        table=AiresInfo.GetLateralTable(InputFolder,2205,Density=False,Precision="Simple")
        SimShower.SimShowerWriteLDFeplusminus(HDF5handle, RunID, EventID, table.T[1])

        table=AiresInfo.GetLateralTable(InputFolder,2006,Density=False,Precision="Simple")
        SimShower.SimShowerWriteLDFeplus(HDF5handle, RunID, EventID, table.T[1])

        table=AiresInfo.GetLateralTable(InputFolder,2207,Density=False,Precision="Simple")
        SimShower.SimShowerWriteLDFmuplusminus(HDF5handle, RunID, EventID, table.T[1])

        table=AiresInfo.GetLateralTable(InputFolder,2007,Density=False,Precision="Simple")
        SimShower.SimShowerWriteLDFmuplus(HDF5handle, RunID, EventID, table.T[1])

        table=AiresInfo.GetLateralTable(InputFolder,2291,Density=False,Precision="Simple")
        SimShower.SimShowerWriteLDFallcharged(HDF5handle, RunID, EventID, table.T[1])

    ################################################################################################################################
    # Energy Distribution at ground Tables
    #################################################################################################################################
    if(EnergyDistribution):
        #the gammas
        table=AiresInfo.GetLateralTable(InputFolder,2501,Density=False,Precision="Simple")
        SimShower.SimShowerWriteEnergyDist_energy(HDF5handle, RunID, EventID, table.T[0])
        SimShower.SimShowerWriteEnergyDist_gammas(HDF5handle, RunID, EventID, table.T[1])

        table=AiresInfo.GetLateralTable(InputFolder,2705,Density=False,Precision="Simple")
        SimShower.SimShowerWriteEnergyDist_eplusminus(HDF5handle, RunID, EventID, table.T[1])

        table=AiresInfo.GetLateralTable(InputFolder,2506,Density=False,Precision="Simple")
        SimShower.SimShowerWriteEnergyDist_eplus(HDF5handle, RunID, EventID, table.T[1])

        table=AiresInfo.GetLateralTable(InputFolder,2707,Density=False,Precision="Simple")
        SimShower.SimShowerWriteEnergyDist_muplusminus(HDF5handle, RunID, EventID, table.T[1])

        table=AiresInfo.GetLateralTable(InputFolder,2507,Density=False,Precision="Simple")
        SimShower.SimShowerWriteEnergyDist_muplus(HDF5handle, RunID, EventID, table.T[1])

        table=AiresInfo.GetLateralTable(InputFolder,2791,Density=False,Precision="Simple")
        SimShower.SimShowerWriteEnergyDist_allcharged(HDF5handle, RunID, EventID, table.T[1])

    logging.info("### The event written was " + EventName)

    f.Close()
    print("****************CLOSED!")
    
    return EventName


#def ZHAiresRawToSimShowerRun(FileName, RunID, EventID, InputFolder):


# TODO: This should probably be part of GRANDRoot.py.?
# Check if the EventID does not already exist in the TTrees
# TODO: Which TTree has all the IDs? Now checking just 2 of them

def CheckIfEventIDIsUnique(EventID, f):
    # Try to get the tree from the file
    try:
        SimShower_tree = f.SimShower
        # This readout should be done with RDataFrame, but it crashes on evt_id :/
        # So doing it the old, ugly way
        # TODO: Ask why it crashes on the ROOT forum and switch to RDataFrame!
        SimShower_tree.Draw("evt_id", "", "goff")
        EventIDs = np.frombuffer(SimShower_tree.GetV1(), dtype=np.float64, count=SimShower_tree.GetSelectedRows()).astype(int)

    # SimShower TTree doesn't exist -> look for SimEfield
    except:
        try:
            SimEfield_tree = f.SimEfield
            SimEfield_tree.Draw("evt_id", "", "goff")
            EventIDs = np.frombuffer(SimEfield_tree.GetV1(), dtype=np.float64, count=SimEfield_tree.GetSelectedRows()).astype(int)

        # No trees - any EventID will do
        except:
            return True

    # If the EventID is already in the trees' EventIDs, return False
    if EventID in EventIDs:
        return False

    return True


if __name__ == '__main__':

	if (len(sys.argv)>6 or len(sys.argv)<6) :
		print("Please point me to a directory with some ZHAires output, and indicate the mode RunID, EventID and output filename...nothing more, nothing less!")
		print("i.e ZHAiresRawToGRANDROOT ./MyshowerDir full RunID EventID MyFile.root")
		mode="exit"

	elif len(sys.argv)==6 :
		inputfolder=sys.argv[1]
		mode=sys.argv[2]
		RunID=int(sys.argv[3])
		EventID=int(sys.argv[4])
		FileName=sys.argv[5]
#		HDF5handle= h5py.File(FileName, 'a')

	if(mode=="standard"):
		ZHAiresRawToGRANDROOT(HDF5handle,RunID,EventID,inputfolder)

	elif(mode=="full"):

		ZHAiresRawToGRANDROOT(HDF5handle,RunID,EventID,inputfolder, SimEfieldInfo=True, NLongitudinal=True, ELongitudinal=True, NlowLongitudinal=True, ElowLongitudinal=True, EdepLongitudinal=True, LateralDistribution=True, EnergyDistribution=True)

	elif(mode=="minimal"):
	
		ZHAiresRawToGRANDROOT(FileName,RunID,EventID,inputfolder,	SimEfieldInfo=True, NLongitudinal=False, ELongitudinal=False, NlowLongitudinal=False, ElowLongitudinal=False, EdepLongitudinal=False, LateralDistribution=False, EnergyDistribution=False)

	else:

		print("please enter one of these modes: standard, full or minimal")
		
		
"""
Notes:
	0) I don't see SimSignal in the HDF5 file
	1) Not all SimShower_EventInfo are initialised, for example atmos_model_param
	2) run_id is int32 in SimShower_EventInfo and SimShower_RunInfo, but a string in SimEfield_EventInfo
	4) Do the strings in the arrays have constant length? If so, I should change the data type
	5) At the moment I have 6 vectors in GRANDTrace class: SimSignal/Efield_X/Y/Z. But they are inside the class just to "look" like a single structure in a browser. In reality they are split into 6 separate branches. Perhaps if we split them from the start, it is better? Or pehaps we should hold (x,y,z) points in a single branch, instead of having separate x,y,z branches?
	6) Should SimShower_EventInfo.evt_id be a string? Int is written into this string now. Same prim_type, SimEfield_RunInfo.run_id, SimEfield_EventInfo.evt_id
	7) There are some unoptimal solutions now, like in SimEfield_DetectorIndex constant size variable are vectors
	8) The values that are not filled in this script, like DetectorIndex.p2p are empty in the Tree for now (of course, I could fill them with some default value)
	9) SimEfield_DetectorIndex row 0 and 1 seem to be repeated in HDF5. They are not repeated in ROOT. Should they be?
"""
 

