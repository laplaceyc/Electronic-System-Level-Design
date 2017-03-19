// slave1.h
#include "packet.h"
#include <fstream>
#include <iostream>

SC_MODULE(slave1) {
    sc_in<packet_type> rpackin;
    sc_out<packet_type> rpackout;
    sc_out<sc_uint<8> > dout;
    sc_in<bool> rclk;

    int framenum;
    packet_type packin, packold;
    packet_type s;
    int retry;
	
	sc_uint<8> slave1_reg[16];
	
	ofstream slave1_log;
	
    void receive_data();

    //Constructor
    SC_CTOR(slave1) {
		slave1_log.open("Slave1Log.txt",ios::out);	
		
        SC_METHOD(receive_data);
        sensitive << rclk.pos();
        framenum = 1;
        retry = 1;
    }
};
