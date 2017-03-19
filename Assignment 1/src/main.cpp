// main.cpp
#include "packet.h"
#include "timer.h"
#include "master.h"
#include "noisybus.h"
#include "slave1.h"
#include "display.h"
#include "memory.h"

int sc_main(int argc, char* argv[]) {
    sc_signal<packet_type>	PACKET1, PACKET2, PACKET3, PACKET4, PACKET5, PACKET6;
    sc_signal<sc_uint<8> > DOUT;
    sc_signal<bool> TIMEOUT, START;
    sc_clock CLOCK("clock", sc_time(20,SC_NS));	// master clock
    sc_clock RCLK("rclk", sc_time(15,SC_NS));	// slave1 clock

    master t1("transimit");   // master instantiation
    t1.tpackin(PACKET2);      // port to signal binding
    t1.timeout(TIMEOUT);
    t1.tpackout(PACKET1);
    t1.start_timer(START);
    t1.clock(CLOCK);          // clocking

    noisybus n1("noisybus");    // noisybus instantiation
    n1.tpackin(PACKET1);        // connect to master
    n1.rpackin(PACKET3);        // port to signal binding (slave)
    n1.mpackin(PACKET5);		// port to signal binding (memory)
    n1.tpackout(PACKET2);       // connect to master
    n1.rpackout(PACKET4);       // port to signal binding (slave)
    n1.mpackout(PACKET6);		// port to signal binding (memory)
    
    memory m1("memory");     // memory instantiation
    m1.mpackin(PACKET6);	 // connect to noisybus
    m1.mpackout(PACKET5);	 // connect to noisybus
    m1.rclk(RCLK);	         // clocking

    slave1 r1("slave1");     // slave1 instantiation
    r1.rpackin(PACKET4);	 // connect to noisybus
    r1.rpackout(PACKET3);	 // connect to noisybus
    r1.dout(DOUT);	         // port to signal binding
    r1.rclk(RCLK);	         // clocking

    	
    display d1("display");	 // display instantiation
    d1.din(DOUT);            // port to signal binding

    timer tm1("timer");	  // timer instantiation
    tm1.start(START);     // port to signal binding
    tm1.timeout(TIMEOUT); 
    tm1.clock(CLOCK); 


    // tracing:
    // trace file creation, with VCD type output
    sc_trace_file *tf = sc_create_vcd_trace_file("simplex");
    // External signals
    sc_trace(tf, CLOCK, "clock");
    sc_trace(tf, TIMEOUT, "timeout");
    sc_trace(tf, START, "start");
    sc_trace(tf, PACKET1, "packet1");
    sc_trace(tf, PACKET2, "packet2");
    sc_trace(tf, PACKET3, "packet3");
    sc_trace(tf, PACKET4, "packet4");
    sc_trace(tf, DOUT, "dout");

    sc_start(100000, SC_NS);	// simulate for 10000 time steps 

    sc_close_vcd_trace_file(tf);

    return(0);
}
