// MA_filter.h
#include "systemc.h"
#ifndef _MA_FILTER_H
#define _MA_FILTER_H
SC_MODULE(MA_filter){
	sc_in<sc_uint<32> >	input;
	sc_out<sc_uint<32> > output;
	sc_in<bool>	rst;
	sc_in<bool>	clk;
	void prc_MA_filter();
	sc_uint<32> x, y;
	sc_signal<sc_uint<32> > mid0, mid1, mid2, mid3,\
							mid4, mid5, mid6, mid7,\
							mid8, mid9, mid10, mid11,\
							mid12, mid13, mid14, mid15;	
	sc_uint<32>	b0;
	// Constructor
	SC_CTOR(MA_filter) {
		SC_CTHREAD(prc_MA_filter, clk.pos());
		reset_signal_is(rst, true);
	}
};
#endif