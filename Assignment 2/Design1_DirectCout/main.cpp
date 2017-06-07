// full_adder.h
#include "systemc.h"
#include "HA.h"
#include "FA.h"

int sc_main(int argc, char** argv){
	sc_signal<bool> t_H_A , t_H_B , t_H_Sum , t_H_Carry; // half adder signal
	sc_signal<bool> t_F_A , t_F_B , t_F_Cin , t_F_S, t_F_Cout; // full adder signal
	
	
	HA h1("halfadder"); // half adder instantiation
	//port to signal binding
	h1.A(t_H_A);
	h1.B(t_H_B);
	h1.Sum(t_H_Sum);
	h1.Carry(t_H_Carry);

	FA f1("fulladder"); // full adder instantiation
	//port to signal binding
	f1.A(t_F_A);
	f1.B(t_F_B);
	f1.Cin(t_F_Cin);
	f1.S(t_F_S);
	f1.Cout(t_F_Cout);
	
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
			sc_start(sc_time(10, SC_NS));
			cout << "[Full Adder] At time " << sc_time_stamp() << "::";
			cout << "(A, B, Cin): ";
			cout << t_F_A << t_F_B << t_F_Cin;
			cout << " (Cout, Sum): ";
			cout << t_F_Cout << t_F_S << endl;
		}

	}
	cout << "Info: End of full adder simulation...\n";
	round = 4;
	cout << "Info: Begin half adder simulation...\n";
	while(round--){
		for(counter = 0; counter < 5; counter++){
			t_H_B = counter[0].to_bool();
			t_H_A = counter[1].to_bool();
			sc_start(sc_time(10, SC_NS));
			cout << "[Half Adder] At time " << sc_time_stamp() << "::";
			cout << "(A, B): ";
			cout << t_H_A << t_H_B;
			cout << " (Carry, Sum): ";
			cout << t_H_Carry << t_H_Sum << endl;
		}
	}
	cout << "Info: End of half adder simulation...\n";
	sc_close_vcd_trace_file(tf);
	
	return (0);
}