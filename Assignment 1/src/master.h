// master.h
#include "packet.h"	
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

SC_MODULE (master) {
	sc_in<packet_type>	tpackin;
	sc_in<bool>	timeout;
	sc_out<packet_type>	tpackout;
	sc_inout<bool>	start_timer;
	sc_in<bool>	clock;

	sc_uint<32> addr_buffer;
	sc_uint<8> data_buffer;
	bool instr_buffer;
	int framenum;
	packet_type packin, tpackold;
	packet_type s;
	packet_type r;
	int retry;
	bool start;
	ifstream infile;
  	ofstream outFile;
	  
	void send_data();
	void receive_data();
	void get_data_from_pkt(bool &instr, sc_uint<32> &addr, sc_uint<8> &data);

	// Constructor
	SC_CTOR(master) {
		SC_METHOD(send_data);
		sensitive << timeout;
		sensitive << clock.pos();
		infile.open("MasterData.txt");//new
		outFile.open("MasterLog.txt", ios::out); //NEW
		framenum = 1;
		retry = 0;
		start = false;
		get_data_from_pkt(instr_buffer, addr_buffer, data_buffer);
		
		SC_METHOD(receive_data);
        sensitive << tpackin;
	}
};
