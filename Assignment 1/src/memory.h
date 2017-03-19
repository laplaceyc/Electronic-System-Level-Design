// memory.h
#include "packet.h"
#include <fstream>
#include <iostream>


SC_MODULE(memory) {
    sc_in<packet_type> mpackin;
    sc_out<packet_type> mpackout;
    //sc_out<sc_uint<8> > dout;
    sc_in<bool> rclk;
	
	ofstream memory_log;
	
    int framenum;
    packet_type packin, packold;
    packet_type s;
    int retry;
	
	sc_uint<8> memory_reg[256];
	
    void receive_data();

    //Constructor
    SC_CTOR(memory) {
		memory_log.open("MemoryLog.txt",ios::out); //NEW	
		
        SC_METHOD(receive_data);
        sensitive << rclk.pos();
        framenum = 1;
        retry = 1;
    }
};

