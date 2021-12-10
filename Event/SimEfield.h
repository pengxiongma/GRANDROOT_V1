/*************************************************************************
    > File Name: _Format_data_grand.cpp
    > Author: Ma PengXiong
    > Mail: 1182905413@qq.com 
    > Created Time: 2021年03月16日 星期二 14时54分40秒
 ************************************************************************/
#ifndef SimEfield_H
#define SimEfield_H

#include <vector>
#include "TObject.h"
#include "TVector3.h"
using namespace std;


class SimEfield : public TObject
{
	public:
int run_id;
int evt_id;
vector<string> field_sim ;
vector<string> refractivity_model;
float refractivity_param1;
float refractivity_param2;
float t_pre ;
float t_post;
float t_bin_size   ;
vector<int> Detectors_det_id ;
vector<vector<string> > Detectors_det_type;
vector<vector<float> > Detectors_det_pos_shc  ;
vector<float> Detectors_t_0 ;
vector<float> Detectors_p2p  ;
vector<float> Detectors_p2p_x  ;
vector<float> Detectors_p2p_y  ;
vector<float> Detectors_p2p_z  ;
vector<vector<float>> Detectors_trace_x;
vector<vector<float>> Detectors_trace_y;
vector<vector<float>> Detectors_trace_z;
   ClassDef(SimEfield,1)
};

#endif
