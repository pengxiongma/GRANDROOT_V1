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
		vector<vector<TVector3> > Detectors_trace;


        vector<float> Get_T_0()
        {
        	return Detectors_t_0;
        }
        vector<vector<TVector3>> Get_Voltage()
        {
        	return Detectors_trace;
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
