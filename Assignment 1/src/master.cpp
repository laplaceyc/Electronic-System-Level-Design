// master.cpp
#include "master.h"
#include <iomanip>
using namespace std;
void master::get_data_from_pkt(bool &instr, sc_uint<32> &addr, sc_uint<8> &data) {

	string s1;
	getline(infile,s1);
	cout << "----------------------------------------------" << endl;
	cout << "Master Read File = " << s1 << "\n";
	if(s1.size() > 15)
	{
		cout << "Invalid input was found in MasterLog.txt, it is " << s1 << endl;
		outFile << "Invalid input was found in MasterLog.txt, it is " << s1 << endl;
		getline(infile,s1);
		cout << "----------------------------------------------" << endl;
		cout << "Master Read File = " << s1 << "\n";
	}
	stringstream ss(s1);
	string tmp_buf;
	ss >> tmp_buf;
	instr = stoi(tmp_buf);
	ss >> tmp_buf;
	addr = stoi(tmp_buf, nullptr, 16);
	data = 0;
	if(instr) ss >> tmp_buf;
	data = stoi(tmp_buf);
	cout << "Parsing data: " << "[Instr] " << instr << "[Addr] " << addr << "[Data] " << data << endl;
	return;
}

void master::send_data() {
	if (timeout) {
		s.data = data_buffer;
		s.addr = addr_buffer;
		s.rw = instr_buffer;
		s.seq = framenum;
		
		if(s.rw == true) {
			cout << "Timeout on \"Write 0x" << setw(4) << uppercase << setfill('0')  << hex << s.addr.to_uint() << nouppercase << " " << dec << s.data << "\"\n";
			outFile << "Timeout on \"Write 0x" << setw(4) << uppercase << setfill('0')  << hex << s.addr.to_uint() << nouppercase << " " << dec << s.data << "\"\n";
		}
		else{
			cout << "Timeout on \"Read 0x" << setw(4) << uppercase << setfill('0')  << hex << s.addr.to_uint() << nouppercase << dec <<"\"\n";
			outFile << "Timeout on \"Read 0x" << setw(4) << uppercase << setfill('0')  << hex << s.addr.to_uint() << nouppercase << dec <<"\"\n";
		}
		tpackout = s;
		start_timer = true;
		cout << "Master: Sending packet no. " << s.seq << endl;
		
	} else {
		packin = tpackin;
		if (!(packin == tpackold)) {
		   if (packin.seq == framenum) {
		        get_data_from_pkt(instr_buffer, addr_buffer, data_buffer);
		        framenum++;
		   }
		   tpackold = tpackin;
		   s.data = data_buffer;
		   s.addr = addr_buffer;
		   s.rw = instr_buffer;
		   s.seq = framenum;
		   tpackout = s;
		   start_timer = true;
		   cout << "Master: Sending packet no. " << s.seq << endl;
}	}	}

void master::receive_data(){
	r = tpackin;
	cout << "Master: Receive packet no. " << r.seq << endl;
	
	//1: Write; 0: Read
	if(r.rw == true) {//write phase
		cout << "Write 0x" << setw(4) << uppercase << setfill('0') << hex << r.addr.to_uint() << nouppercase << " " << dec << r.data;
		outFile << "Write 0x" << setw(4) << uppercase << setfill('0') << hex << r.addr.to_uint() << nouppercase << " " << dec << r.data;
		if(r.ack == true) {cout << ", Aak\n"; 
					   outFile << ", Aak\n";
		} 
		else {cout << ", Nak\n";
			outFile << ", Nak\n";
		} 
	}
	else{//read phase
		cout << "Read 0x" << setw(4) << uppercase << setfill('0') << hex << r.addr.to_uint() << nouppercase << " " << dec << r.data;
		outFile << "Read 0x" << setw(4) << uppercase << setfill('0') << hex << r.addr.to_uint() << nouppercase << " " << dec << r.data;
		if(r.ack == true) {cout << ", Aak\n"; 
					   outFile << ", Aak\n";
		} 
		else {cout << ", Nak\n";
			outFile << ", Nak\n";
		} 
	}
	}
	
