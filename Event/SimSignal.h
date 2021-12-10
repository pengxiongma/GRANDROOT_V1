/*************************************************************************
    > File Name: _Format_data_grand.cpp
    > Author: Ma PengXiong
    > Mail: 1182905413@qq.com 
    > Created Time: 2021年03月16日 星期二 14时54分40秒
 ************************************************************************/
#ifndef SimSignal_H
#define SimSignal_H

#include <vector>
#include "TObject.h"
#include "TVector3.h"
using namespace std;


class SimSignal : public TObject
{
	public:
		int run_id;
		int evt_id;
		vector<string> signal_sim   ;
		vector<int> Detectors_det_id ;
		vector<vector<string> > Detectors_det_type ;
		vector<vector<float> > Detectors_det_pos_shc ;
		vector<float> Detectors_t_0  ;
		vector<float>  Detectors_p2p ;
		vector<vector<float>> Detectors_trace_x;
		vector<vector<float>> Detectors_trace_y;
		vector<vector<float>> Detectors_trace_z;
		vector<vector<float>> Voltage_trace_x;
		vector<vector<float>> Voltage_trace_y;
		vector<vector<float>> Voltage_trace_z;


        vector<float> Get_T_0()
        {
        	return Detectors_t_0;
        }
        vector<float> Get_P2P()
        {
        	return Detectors_p2p;
        }
        vector<vector<float>> Get_Voltage_X()
        {
        	return Detectors_trace_x;
        }
        vector<vector<float>> Get_Voltage_Y()
        {
        	return Detectors_trace_y;
        }
        vector<vector<float>> Get_Voltage_Z()
        {
        	return Detectors_trace_z;
        }
        
		vector<vector<float>> Get_ADC_X()
        {
        	return Voltage_trace_x;
        }
        vector<vector<float>> Get_ADC_Y()
        {
        	return Voltage_trace_y;
        }
        vector<vector<float>> Get_ADC_Z()
        {
        	return Voltage_trace_z;
        }
        int Get_EvtID( )
        {
        	return evt_id;
        }
        int Get_RunID( )
        {
        	return run_id;
        }
        
		ClassDef(SimSignal,1)
};

#endif
