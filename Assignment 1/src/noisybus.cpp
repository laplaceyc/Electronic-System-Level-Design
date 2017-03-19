// noisybus.cpp
#include "noisybus.h"
#include <iomanip>

void noisybus::receive_data() {
    int i;
    packin = tpackin;
    cout << "Noisybus: Received packet seq no. = " << packin.seq << endl;
    i = rand();
    packout = packin;
    cout << "Noisybus: Random number = " << i << endl;
	
	sc_uint<32> addr = packout.addr;
	
    if ((i > 1000) && (i < 5000)) {
        packout.seq = 0;
		if(packout.rw ==true){
			noisybus_log << "Write 0x" << setw(4) << uppercase << setfill('0')  << hex << addr.to_uint() << nouppercase << dec << " dropped\n";
		}else {
			noisybus_log << "Read 0x" << setw(4) << uppercase << setfill('0')  << hex << addr.to_uint() << nouppercase << dec << " dropped\n";
		}
		
    }

	if( (addr.to_uint() >= 4096) &&  (addr.to_uint() <= 4111) ){ 
		packout.ack = false;
		rpackout = packout;
	}
	else if ( (addr.to_uint() >= 8192) &&  (addr.to_uint() <= 12287) ){ 
		packout.ack = false;
		mpackout = packout;
	}
	else {
		
		fanin_r = packout;

		//Invalid Phase
		packout.ack=false;
		if(packout.rw ==true){
			cout<< "Invalid address 0x" << setw(4) << uppercase << setfill('0')  << hex << addr.to_uint() << nouppercase << dec << ", write failed\n"; //NEW
			noisybus_log << "Invalid address 0x" << setw(4) << uppercase << setfill('0')  << hex << addr.to_uint() << nouppercase << dec << ", write failed\n"; //NEW
		}else {
			cout<< "Invalid address 0x" << setw(4) << uppercase << setfill('0')  << hex << addr.to_uint() << nouppercase << dec << ", read failed\n";  //NEW
			noisybus_log << "Invalid address 0x" << setw(4) << uppercase << setfill('0')  << hex << addr.to_uint() << nouppercase << dec << ", read failed\n";  //NEW
		}

		
	}
    
}

void noisybus::send_ack() {
	cout << "Packet is in noisybus again" << endl;
	if(!(rpackold == rpackin)){
	
	int i;
    ackin = rpackin;
    cout << "Noisybus: Received Ack for packet = " << ackin.seq << endl;
    i = rand();
    ackout = ackin;
    if ((i > 10) && (i < 500)) {
        ackout.seq = 0;
    }
    fanin_s = ackout;
	rpackold = rpackin;
	} 
	else { //mpackold = mpackin;
//	cout << "In another case!! Congratulation\n";
	mpackold = mpackin;
    int i;
    ackin = mpackin;
    cout << "Noisybus: Received Ack for packet = " << ackin.seq << endl;
    i = rand();
    ackout = ackin;
    if ((i > 10) && (i < 500)) {
        ackout.seq = 0;
    }
	ackout.ack = true;
    fanin_s = ackout;
	} 
}



void noisybus::bridge(){
	
	bpackin_s = fanin_s;
	bpackin_r = fanin_r;
	if(!(bpackin_s == bpackold_s)){
		tpackout = bpackin_s;
		bpackold_s = bpackin_s;
	}
	else if(!(bpackin_r == bpackold_r)){
		tpackout = bpackin_r;
		bpackold_r = bpackin_r;
	}
	
	
}
