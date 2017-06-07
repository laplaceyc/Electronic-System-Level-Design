// half_monitor.h
#include "systemc.h"
#ifndef _HALF_MONITOR_H
#define _HALF_MONITOR_H
SC_MODULE(half_monitor){
	sc_in<bool> t_H_A, t_H_B, t_H_Sum, t_H_Carry; // half adder signal

	void prc_monitor(){
		cout << "[Half Adder] At time " << sc_time_stamp() << "::";
		cout << "(A, B): ";
		cout << t_H_A << t_H_B;
		cout << " (Carry, Sum): ";
		cout << t_H_Carry << t_H_Sum << endl;
	
	}
	// Constructor
	SC_CTOR(half_monitor){
		SC_METHOD(prc_monitor);
		sensitive << t_H_A << t_H_B;
	}
};
#endif