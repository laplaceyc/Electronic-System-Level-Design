// full_adder.h
#include "systemc.h"
#include "half_adder.h"
#ifndef _FULL_ADDER_H
#define _FULL_ADDER_H
SC_MODULE(full_adder){
	sc_in<bool> A, B, Cin;
	sc_out<bool> S, Cout;
	sc_signal<bool> c1, s1, c2;
	void prc_cout(){
		Cout = c1 | c2;
	};
	half_adder *ha1_ptr, *ha2_ptr;
	// Constructor
	SC_CTOR(full_adder) {
		ha1_ptr = new half_adder("ha1");
		ha1_ptr->A(A);
		ha1_ptr->B(B);
		ha1_ptr->Sum(s1);
		ha1_ptr->Carry(c1);
		ha2_ptr = new half_adder("ha2");
		ha2_ptr->A(s1);
		ha2_ptr->B(Cin);
		ha2_ptr->Sum(S);
		ha2_ptr->Carry(c2);
		SC_METHOD(prc_cout);
		sensitive << c1 << c2;
	}
	// Destructor
	~full_adder() {
		delete ha1_ptr;
		delete ha2_ptr;
	}
};
#end
