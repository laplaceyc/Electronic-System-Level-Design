// slave1.cpp
#include "slave1.h"
#include <iomanip>

using namespace std;
void slave1::receive_data() {
	
    packin = rpackin;
    if (packin == packold) return;
	
	packold = packin;
	
	sc_uint<32> tmp_addr = packin.addr;

    cout << "Slave1: got packet no. = " << packin.seq << endl;

	int pos = tmp_addr % 16;
	
	if(packin.rw == true){
		slave1_reg[pos] = packin.data;
	}
	else {
		packin.data = slave1_reg[pos];
	}
	
	
	
	
	framenum = packin.seq;
	
    if (packin.seq == framenum) {
        dout = packin.data;
        framenum++;
        s.seq = framenum-1;
		s.addr = packin.addr;
		s.data = packin.data;
		s.rw = packin.rw;
		s.ack = true;
        rpackout = s;
    }
	
	if(packin.rw == true) {
		cout << "Address 0x" << setw(4) << uppercase << setfill('0') << hex << packin.addr.to_uint() << ", write " << nouppercase << dec << packin.data << " successfully\n";
		slave1_log << "Address 0x" << setw(4) << uppercase << setfill('0') << hex << packin.addr.to_uint() << ", write " << nouppercase << dec << packin.data << " successfully\n";
	}
	else{
		cout << "Address 0x" << setw(4) << uppercase << setfill('0') << hex << packin.addr.to_uint() << ", Read " << nouppercase << dec << packin.data << " successfully\n";
		slave1_log << "Address 0x" << setw(4) << uppercase << setfill('0') << hex << packin.addr.to_uint() << ", Read " << nouppercase << dec << packin.data << " successfully\n";
	}

}
