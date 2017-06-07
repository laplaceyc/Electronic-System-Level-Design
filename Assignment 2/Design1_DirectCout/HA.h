// HA.h
#include "systemc.h"
#ifndef _HALF_ADDER_H
#define _HALF_ADDER_H
SC_MODULE(HA){
	sc_in<bool> A, B;
	sc_out<bool> Sum, Carry;
	void prc_half_adder();
	
	// Constructor
	SC_CTOR(HA) {
		SC_METHOD(prc_half_adder);
		sensitive << A << B;
	}
};
#endif