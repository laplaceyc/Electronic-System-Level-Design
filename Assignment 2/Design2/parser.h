// parser.h
#include "systemc.h"
#include <iostream>
#include <fstream>
using namespace std;
#ifndef _PARSER_H
#define _PARSER_H

SC_MODULE(parser){
	sc_in<sc_uint<32> >	input;
	sc_out<sc_uint<32> > output;
	sc_in<bool> clk;
	ifstream inFile;
	sc_uint<32> x, y;
	void prc_parser();

	// Constructor
	SC_CTOR(parser) {
		SC_METHOD(prc_parser);
		sensitive << clk.pos();
		inFile.open("data", ios::in);
	}
};

#endif