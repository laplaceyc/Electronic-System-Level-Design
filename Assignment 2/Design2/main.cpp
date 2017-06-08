// main.cpp
#include "systemc.h"
#include "MA_filter.h"
#include "parser.h"
int sc_main(int argc, char* argv[]) {

    sc_signal<sc_uint<32> > x, y;
    sc_signal<bool> rst;
    sc_clock clk("clock", sc_time(20,SC_NS)); // clock

    MA_filter fir1("FIRFilter");// FIR filter
	//port to signal binding
	fir1.input(x);
	fir1.output(y);
	fir1.clk(clk);
	fir1.rst(rst);
	
	parser p1("parser");//data parser
	//port to signal binding
	p1.input(y);
	p1.output(x);
	p1.clk(clk);
	
	
	
    // tracing:
    // trace file creation, with VCD type output
    sc_trace_file *tf = sc_create_vcd_trace_file("RESULT");
    // External signals
    sc_trace(tf, clk, "clk");
    sc_trace(tf, rst, "rst");
    sc_trace(tf, x, "x");
    sc_trace(tf, y, "y");
    
    sc_start(1300, SC_NS);

    sc_close_vcd_trace_file(tf);

    return(0);
}