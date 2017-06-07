// full_adder.h
#include "systemc.h"
#include "half_adder.h"
#include "full_adder.h"
#include "half_monitor.h"
#include "full_monitor.h"
#ifdef __CTOS__
SC_MODULE_EXPORT(main);
#endif
int sc_main(int argc, char** argv){
	sc_signal<bool> t_H_A , t_H_B , t_H_Sum , t_H_Carry; // half adder signal
	sc_signal<bool> t_F_A , t_F_B , t_F_Cin , t_F_S, t_F_Cout; // full adder signal
	
	
	half_adder h1("halfadder"); // half adder instantiation
	//port to signal binding
	h1.A(t_H_A);
	h1.B(t_H_B);
	h1.Sum(t_H_Sum);
	h1.Carry(t_H_Carry);
	
	half_monitor mh1("halfAdderMonitor"); // monitor for half adder
	//port to signal binding
	mh1.t_H_A(t_H_A);
	mh1.t_H_B(t_H_B);
	mh1.t_H_Sum(t_H_Sum);
	mh1.t_H_Carry(t_H_Carry);
	
	full_adder f1("fulladder"); // full adder instantiation
	//port to signal binding
	f1.A(t_F_A);
	f1.B(t_F_B);
	f1.Cin(t_F_Cin);
	f1.S(t_F_S);
	f1.Cout(t_F_Cout);
	
	full_monitor fh1("fullAdderMonitor"); // monitor for full adder
	//port to signal binding
	fh1.t_F_A(t_F_A);
	fh1.t_F_B(t_F_B);
	fh1.t_F_Cin(t_F_Cin);
	fh1.t_F_S(t_F_S);
	fh1.t_F_Cout(t_F_Cout);
	
	
	// tracing:
    // trace file creation, with VCD type output
    sc_trace_file *tf = sc_create_vcd_trace_file("RESULT");
    // External signals
    sc_trace(tf, t_H_A,         "A");
    sc_trace(tf, t_H_B,         "B");
    sc_trace(tf, t_H_Sum,     "Sum");
    sc_trace(tf, t_H_Carry, "Carry");
    sc_trace(tf, t_F_A,         "A");
    sc_trace(tf, t_F_B,         "B");
    sc_trace(tf, t_F_Cin,     "Cin");
    sc_trace(tf, t_F_S,         "S");
	sc_trace(tf, t_F_Cout,   "Cout");
	
	sc_uint<3> round = 4;
	sc_uint<4> counter;
	cout << "Info: Begin full adder simulation...\n";
	while(round--){
	
		for(counter = 0; counter < 9; counter++){
			t_F_Cin = counter[0].to_bool();
			t_F_B = counter[1].to_bool();
			t_F_A = counter[2].to_bool();
			sc_start(sc_time(10, sc_time_unit::SC_PS));
		}

	}
	cout << "Info: End of full adder simulation...\n";
	round = 4;
	cout << "Info: Begin half adder simulation...\n";
	while(round--){
		for(counter = 0; counter < 5; counter++){
			t_H_B = counter[0].to_bool();
			t_H_A = counter[1].to_bool();
			sc_start(sc_time(10, sc_time_unit::SC_PS));
		}
	}
	cout << "Info: End of half adder simulation...\n";
	sc_close_vcd_trace_file(tf);
	
	return (0);
}