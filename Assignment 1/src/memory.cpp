// memory.cpp
#include "memory.h"
#include <iomanip>

using namespace std;
void memory::receive_data() {
     packin = mpackin;
    if (packin == packold) return;
	
	packold = packin;
	
	sc_uint<32> tmp_addr = packin.addr;

    cout << "Memory: got packet no. = " << packin.seq << endl;

	int pos = tmp_addr % 4096;
	
	if(packin.rw == true){
		memory_reg[pos] = packin.data;
	}
	else {
		packin.data = memory_reg[pos];
	}

	framenum = packin.seq;
	
    if (packin.seq == framenum) {
        //dout = packin.data;
        framenum++;
        s.seq = framenum-1;
		s.addr = packin.addr;
		s.data = packin.data;	
		s.rw = packin.rw;
		s.ack = true;
        mpackout = s;

    }
	// Print phase
	if(packin.rw == true) {
		cout << "Address 0x" << setw(4) << uppercase << setfill('0') << hex << packin.addr.to_uint() << ", write " << nouppercase << dec << packin.data << " successfully\n";
		memory_log << "Address 0x" << setw(4) << uppercase << setfill('0') << hex << packin.addr.to_uint() << ", write " << nouppercase << dec << packin.data << " successfully\n";
	}
	else{
		cout << "Address 0x" << setw(4) << uppercase << setfill('0') << hex << packin.addr.to_uint() << ", Read " << nouppercase << dec << packin.data << " successfully\n";
		memory_log << "Address 0x" << setw(4) << uppercase << setfill('0') << hex << packin.addr.to_uint() << ", Read " << nouppercase << dec << packin.data << " successfully\n";
	}

}
