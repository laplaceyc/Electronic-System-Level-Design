// noisybus.h
#include "packet.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

SC_MODULE (noisybus) {
    sc_in<packet_type> tpackin;
    sc_in<packet_type> rpackin;
    sc_out<packet_type> tpackout;
    sc_out<packet_type> rpackout;
	sc_out<packet_type> mpackout;
	sc_in<packet_type> mpackin;
	
	sc_signal<packet_type> fanin_r, fanin_s;
	

    packet_type packin;
    packet_type packout;
    packet_type ackin;
    packet_type ackout;
	
	packet_type rpackold, mpackold;
	
	packet_type bpackout;
	packet_type bpackin_s, bpackold_s, bpackin_r, bpackold_r;
	
	ofstream noisybus_log;
	
    void receive_data();
    void send_ack();
	void bridge();

    // Constructor
    SC_CTOR(noisybus) {
        noisybus_log.open("NoisybusLog.txt",ios::out);
		
		SC_METHOD(receive_data);
        sensitive << tpackin;
		
        SC_METHOD(send_ack);
        sensitive << rpackin;
        sensitive << mpackin;
		
		SC_METHOD(bridge);
		sensitive << fanin_r;
		sensitive << fanin_s;
		
		
    }
};
