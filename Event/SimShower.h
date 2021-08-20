/*************************************************************************
    > File Name: SimShower.h
    > Author: Ma PengXiong
    > Mail: 1182905413@qq.com 
    > Created Time: Thu 22 Jul 2021 10:04:34 PM CST
 ************************************************************************/

#ifndef SimShower_H
#define SimShower_H

#include <vector>
#include "TObject.h"
#include "TVector3.h"
using namespace std;

class SimShower : public TObject
{
	public:
		int run_id;
		int evt_id;
		vector<string> shower_type;
		float shower_energy;
		float shower_azimuth;
		float shower_zenith;
		vector<float> shower_core_pos;
		double rnd_seed;
		float energy_in_neutrinos;
		vector<string> atmos_model;
		vector<float> atmos_model_param;
		vector<float> magnetic_field;
		vector<string> date;
		vector<string> site;
		vector<float> site_lat_long;
		float ground_alt;
		float prim_energy;
		vector<string> prim_type;
		vector<float> prim_injpoint_shc;
		float prim_inj_alt_shc;
		vector<float> prim_inj_dir_shc;
		float xmax_grams;
		vector<double> xmax_pos_shc;
		double xmax_alt;
		vector<float> gh_fit_param;
		vector<string> hadronic_model;
		vector<string> low_energy_model;
		vector<float> cpu_time;
		int Get_primary_EvtID( )
		{
			return evt_id;
		}
		int Get_primary_RunID( )
		{
			return run_id;
		}
		float Get_primary_Energy( )
		{
			return shower_energy;
		}
		float Get_primary_Zenith( )
		{
			return shower_zenith;
		}
		float Get_primary_Azimuth( )
		{
			return shower_azimuth;
		}
		float Get_primary_RND( )
		{
			return rnd_seed;
		}
		float Get_primary_Xmaxg( )
		{
			return xmax_grams;
		}
		float Get_primary_Xmaxalt( )
		{
			return xmax_alt;
		}
		float Get_primary_Eneutrinos( )
		{
			return energy_in_neutrinos;
		}


		ClassDef(SimShower,1)



};
#endif
