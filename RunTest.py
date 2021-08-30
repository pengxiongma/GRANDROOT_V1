#!/usr/bin/env python3
import sys
import os
import logging
import ZHAireSRawToGRANDROOT as ZHAireS2ROOT
import ComputeVoltageOnGRANDROOT as ComputeVoltage


if ( len(sys.argv)<2 ):
    print("usage python RunTest.py outputfile")
    sys.exit(-1)
if ( len(sys.argv)==2 ):
    outputfile=sys.argv[1]

outputfile=sys.argv[1]
inputname = sys.argv[2] 
runid = int(sys.argv[3])
eventid = int(sys.argv[4])

try:
    os.mkdir("./GeneratedROOT")
except:
    logging.debug("./GeneratedROOT Exists...good")

outputfile="./GeneratedROOT/"+outputfile


#inputfolder="./example-events/event1"
#ZHAireS2ROOT.ZHAiresRawToGRANDROOT(outputfile,0,1,inputfolder,	SimEfieldInfo=True, NLongitudinal=False, ELongitudinal=False, NlowLongitudinal=False, ElowLongitudinal=False, EdepLongitudinal=False, LateralDistribution=False, EnergyDistribution=False)
#
#inputfolder="./example-events/event2"
#ZHAireS2ROOT.ZHAiresRawToGRANDROOT(outputfile,0,2,inputfolder,	SimEfieldInfo=True, NLongitudinal=False, ELongitudinal=False, NlowLongitudinal=False, ElowLongitudinal=False, EdepLongitudinal=False, LateralDistribution=False, EnergyDistribution=False)
#
#inputfolder="./example-events/event3"
#ZHAireS2ROOT.ZHAiresRawToGRANDROOT(outputfile,0,3,inputfolder,	SimEfieldInfo=True, NLongitudinal=False, ELongitudinal=False, NlowLongitudinal=False, ElowLongitudinal=False, EdepLongitudinal=False, LateralDistribution=False, EnergyDistribution=False)

#inputfolder="./example-events/eventmapx4"
#ZHAireS2ROOT.ZHAiresRawToGRANDROOT(outputfile,0,4,inputfolder,	SimEfieldInfo=True, NLongitudinal=False, ELongitudinal=False, NlowLongitudinal=False, ElowLongitudinal=False, EdepLongitudinal=False, LateralDistribution=False, EnergyDistribution=False)
#
#inputfolder="/Users/mapx/Software/GRAND_Detector/GRANDRoot/example-events/Zenith75_differentAzimuth/Azimuth90_newSeting"
#ZHAireS2ROOT.ZHAiresRawToGRANDROOT(outputfile,0,5,inputfolder,	SimEfieldInfo=True, NLongitudinal=False, ELongitudinal=False, NlowLongitudinal=False, ElowLongitudinal=False, EdepLongitudinal=False, LateralDistribution=False, EnergyDistribution=False)
#
#inputfolder="/Users/mapx/Software/GRAND_Detector/GRANDRoot/example-events/Zenith75_differentAzimuth/Azimuth45"
#ZHAireS2ROOT.ZHAiresRawToGRANDROOT(outputfile,1,6,inputfolder,	SimEfieldInfo=True, NLongitudinal=False, ELongitudinal=False, NlowLongitudinal=False, ElowLongitudinal=False, EdepLongitudinal=False, LateralDistribution=False, EnergyDistribution=False)
#
#inputfolder="/Users/mapx/Software/GRAND_Detector/GRANDRoot/example-events/Azimuth135_Gamma"
#ZHAireS2ROOT.ZHAiresRawToGRANDROOT(outputfile,2,7,inputfolder,	SimEfieldInfo=True, NLongitudinal=False, ELongitudinal=False, NlowLongitudinal=False, ElowLongitudinal=False, EdepLongitudinal=False, LateralDistribution=False, EnergyDistribution=False)
#
#inputfolder="/Users/mapx/Software/GRAND_Detector/GRANDRoot/example-events/Azimuth90_Gamma"
#ZHAireS2ROOT.ZHAiresRawToGRANDROOT(outputfile,3,8,inputfolder,	SimEfieldInfo=True, NLongitudinal=False, ELongitudinal=False, NlowLongitudinal=False, ElowLongitudinal=False, EdepLongitudinal=False, LateralDistribution=False, EnergyDistribution=False)
#
#inputfolder="/Users/mapx/Software/GRAND_Detector/GRANDRoot/example-events/Azimuth90_Gamma_10EeV"
#ZHAireS2ROOT.ZHAiresRawToGRANDROOT(outputfile,4,9,inputfolder,	SimEfieldInfo=True, NLongitudinal=False, ELongitudinal=False, NlowLongitudinal=False, ElowLongitudinal=False, EdepLongitudinal=False, LateralDistribution=False, EnergyDistribution=False)
#
#inputfolder="/Users/mapx/Software/GRAND_Detector/GRANDRoot/example-events/Azimuth135_Gamma_3EeV"
#ZHAireS2ROOT.ZHAiresRawToGRANDROOT(outputfile,5,10,inputfolder,	SimEfieldInfo=True, NLongitudinal=False, ELongitudinal=False, NlowLongitudinal=False, ElowLongitudinal=False, EdepLongitudinal=False, LateralDistribution=False, EnergyDistribution=False)

inputfolder = inputname
ZHAireS2ROOT.ZHAiresRawToGRANDROOT(outputfile,runid,eventid,inputfolder,	SimEfieldInfo=True, NLongitudinal=False, ELongitudinal=False, NlowLongitudinal=False, ElowLongitudinal=False, EdepLongitudinal=False, LateralDistribution=False, EnergyDistribution=False)


#ComputeVoltage.ComputeVoltageOnROOT(outputfile)


#ComputeVoltageOnROOT(inputfile)

