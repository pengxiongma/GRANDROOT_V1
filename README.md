# GRANDRoot
Development of the GRAND root file format
This is work in progress. 

Python packages required: os,sys,loogging, numpy,matplotlib,scipy,glob and PyROOT 

#Setting up PyROOT (i had to set this up, your experience might be different)
export LD_LIBRARY_PATH=$ROOTSYS/lib:$PYTHONDIR/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$ROOTSYS/lib:$PYTHONPATH

To test the suite you can do

python3 RunTest.py TestFile.root inputfolder runid eventid
python3 PlotEventRoot.py TestFile.root 



NOTE: Event2 has no traces ON PURPOSE to test what happens when the trees have different number of entries

Since im not experienced in github, lets follow this simple development scheme, and see how it works.

https://guides.github.com/introduction/flow/


NOTE: classes in folder Event, please change the line 54-56 in ZHAireSRawToGRANDROOT.py for its path.


When reading ROOT file, firstly we need to create dictionary and .so files for these classes as below

Step1 : cd Event ; 

Step2 : rootcling -f SimEventDict.cxx -c  SimEfield.h SimSignal.h SimShower.h  SimuEventLinkDef.h ; 

Step3 : g++ -o libSimuEvent.so -shared -fPIC $(root-config --cflags --ldflags)  SimEventDict.cxx

!!!!!please don't forget export LD_LIBRARY_PATH=$PWD/Event:$LD_LIBRARY_PATH in directory ../Event

Step4 : g++  _Readfile_example.cpp -o a.out $(root-config --libs  --cflags) -LEvent -I Event -lSimuEvent


