// FA.h
#include "systemc.h"
#include "HA.h"

#ifndef _FULL_ADDER_H
#define _FULL_ADDER_H
SC_MODULE(FA){
	sc_in<bool> A, B, Cin;
	sc_out<bool> S, Cout;
	sc_signal<bool> c1, s1, c2;
	void prc_cout();
	HA *ha1_ptr, *ha2_ptr;
	// Constructor
	SC_CTOR(FA) {
		ha1_ptr = new HA("ha1");
		ha1_ptr->A(A);
		ha1_ptr->B(B);
		ha1_ptr->Sum(s1);
		ha1_ptr->Carry(c1);
		ha2_ptr = new HA("ha2");
		ha2_ptr->A(s1);
		ha2_ptr->B(Cin);
		ha2_ptr->Sum(S);
		ha2_ptr->Carry(c2);
		SC_METHOD(prc_cout);
		sensitive << c1 << c2;
	}
	// Destructor
	~FA() {
		delete ha1_ptr;
		delete ha2_ptr;
	}
};
#endif