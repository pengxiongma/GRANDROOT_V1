#!/usr/bin/env python3
import sys
import ZHAireSRawToGRANDROOT as ZHAireS2ROOT
import ComputeVoltageOnGRANDROOT as ComputeVoltage


if ( len(sys.argv)<2 ):
    print("usage python RunTest.py outputfile")
    sys.exit(-1)
if ( len(sys.argv)==2 ):
    outputfile=sys.argv[1]


ComputeVoltage.ComputeVoltageOnROOT(outputfile)


#ComputeVoltageOnROOT(inputfile)

