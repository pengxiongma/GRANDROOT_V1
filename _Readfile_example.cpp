/*************************************************************************
    > File Name: _Readfile.cpp
    > Author: Ma PengXiong
    > Mail: 1182905413@qq.com 
    > Created Time: Thu Jul  8 21:26:40 2021
 ************************************************************************/
#include <fstream>
#include <iostream>
#include "TFile.h"
#include "TSystem.h"
#include "TString.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TVector3.h"
#include <vector>
#include "Event/SimEfield.h"
#include "Event/SimSignal.h"
#include "Event/SimShower.h"
using namespace std;
void _Readfile();
int main(){
	_Readfile();
	return 0;
}
void _Readfile()
{
	TCanvas *TC = new TCanvas();
	TC->SetTickx();
	TC->SetTicky();
//    gSystem->Load("/home/mapx/mapx/GRAND_Detector/Event/libSimuEvent.so");
	Float_t shower_energy;
	Float_t shower_zenith;
	Float_t shower_azimuth;
	SimEfield *efield = new SimEfield();
	SimSignal *vsignal = new SimSignal();
	SimShower *sshower = new SimShower();
	TFile *f1 = new TFile("/home/mapx/mapx/MySpace/GRANDROOT_V1/GeneratedROOT/Gamma_energy0.3EeV_check_part_Aug30.root");
	TTree *tre = (TTree*)f1->Get("SimuCollection");
	tre->SetBranchAddress("SimEfieldBranch", &efield);
	tre->SetBranchAddress("SimSignalBranch", &vsignal);
	tre->SetBranchAddress("SimShowerBranch", &sshower);
	TFile *fcre = new TFile("/home/mapx/mapx/MySpace/GRANDROOT_V1/GeneratedROOT/_Output_Gamma_energy0.3EeV_check_part_Aug30_timedomain.root","recreate");
	int Nenties = tre->GetEntries();
	char FileName[63];
	for(int i=0;i<Nenties;i++)
	{
		tre->GetEntry(i);
		vector<vector<TVector3>> Detectors_trace_1 = vsignal->Get_Voltage();
		int ite=0;
		int ntrace = Detectors_trace_1.size();
		cout<<"ntrace = "<<ntrace<<endl;
		TGraph *vx[ntrace];
		TGraph *vy[ntrace];
		TGraph *vz[ntrace];
		double PosX[322];
		double PosY[322];
		for(int it = 0;it<ntrace;it++)
		{
			float T0 = efield->Detectors_t_0[it];
			float Tpre = efield->t_pre;
			vector<float> pos = efield->Detectors_det_pos_shc[it];
//			cout<<it<<"\t"<<pos[0]<<"\t"<<pos[1]<<"\t"<<pos[2]<<"\t"<<T0<<endl;
			PosX[ite]=pos[0]/1e3;
			PosY[ite]=pos[1]/1e3;
			ite++;
			int Ncheck=0;
			int npoints = Detectors_trace_1[it].size();
			double VX[npoints];
			double VY[npoints];
			double VZ[npoints];
			double Tt[npoints];
			for (int j=0; j<Detectors_trace_1[it].size(); j++)
			{
				Ncheck++;
				double X,Y,Z;
				TVector3 Detectors_trace_2=Detectors_trace_1[it][j];
				X = Detectors_trace_2.x();
				Y = Detectors_trace_2.y();
				Z = Detectors_trace_2.z();
				VX[j]=X;
				VY[j]=Y;
				VZ[j]=Z;
				Tt[j]=T0 + Tpre + 0.5*j;
			}
			vx[it] = new TGraph(npoints,Tt,VX);
			vx[it]->SetMarkerColor(kRed-3);
			vx[it]->SetMarkerStyle(kFullCircle);
			vx[it]->SetName(Form("_Event%d_Antenna%d_Vx",i,it));
			vx[it]->SetTitle(Form("_Event%d_Antenna%d_Vx;Time [ns];Voltage [#muv]",i,it));
			vx[it]->Write();
			vy[it] = new TGraph(npoints,Tt,VY);
			vy[it]->SetMarkerColor(kBlue-2);
			vy[it]->SetMarkerStyle(kFullCircle);
			vy[it]->SetName(Form("_Event%d_Antenna%d_Vy",i,it));
			vy[it]->SetTitle(Form("_Event%d_Antenna%d_Vy;Time [ns];Voltage [#muv]",i,it));
			vy[it]->Write();
			vz[it] = new TGraph(npoints,Tt,VZ);
			vz[it]->SetMarkerColor(kGreen);
			vz[it]->SetMarkerStyle(kFullCircle);
			vz[it]->SetName(Form("_Event%d_Antenna%d_Vz",i,it));
			vz[it]->SetTitle(Form("_Event%d_Antenna%d_Vz;Time [ns];Voltage [#muv]",i,it));
			vz[it]->Write();
		}
//		cout<<"shower_energy = "<<shower_energy<<endl;
		shower_energy = sshower->Get_primary_Energy();
		shower_zenith = 180 - sshower->Get_primary_Zenith();
		shower_azimuth = sshower->Get_primary_Azimuth();
		TGraph AntTG(ite,PosX,PosY);
	    AntTG.SetMarkerColor(kRed-3);
	    AntTG.SetMarkerStyle(kFullStar);
	    AntTG.SetName(Form("_Event%d",i));
	    AntTG.SetTitle(Form("_Event%d_Energy_%.2fEeV_Zenith%.2f_Azimuth%.2f;North-South [km];Eest-West [km]",i,shower_energy,shower_zenith,shower_azimuth) );
		AntTG.Write();
		AntTG.Draw("AP");
//		TC->SaveAs(Form("./Event_Antennas_PDF/_EventID%d_Gamma_3Events_dunhuangLenghu.pdf",i));
		TC->SaveAs(Form("_EventID%d_Gamma_3Events_dunhuangLenghu.pdf",i));
	}
	fcre->Write();
}
