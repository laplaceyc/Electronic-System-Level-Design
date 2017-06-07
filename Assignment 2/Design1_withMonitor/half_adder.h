// half_adder.h
#include "systemc.h"
#ifndef _HALF_ADDER_H
#define _HALF_ADDER_H
SC_MODULE(half_adder){
	sc_in<bool> A, B;
	sc_out<bool> Sum, Carry;
	void prc_half_adder(){
		Sum = A ^ B;
		Carry = A & B;
	}
	// Constructor
	SC_CTOR(half_adder) {
		SC_METHOD(prc_half_adder);
		sensitive << A << B;
	}
};
#endif