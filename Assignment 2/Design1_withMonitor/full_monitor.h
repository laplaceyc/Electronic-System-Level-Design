// full_monitor.h
#include "systemc.h"
#ifndef _FULL_MONITOR_H
#define _FULL_MONITOR_H
SC_MODULE(full_monitor){
	sc_in<bool> t_F_A, t_F_B, t_F_Cin, t_F_S, t_F_Cout; // full adder signal
	void prc_monitor(){
		cout << "[Full Adder] At time " << sc_time_stamp() << "::";
		cout << "(A, B, Cin): ";
		cout << t_F_A << t_F_B << t_F_Cin;
		cout << " (Cout, Sum): ";
		cout << t_F_Cout << t_F_S << endl;
	
	}
	// Constructor
	SC_CTOR(full_monitor){
		SC_METHOD(prc_monitor);
		sensitive << t_F_A << t_F_B << t_F_Cin;
	}
};

#endif