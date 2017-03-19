// packet.cpp file
#define SC_USE_SC_STRING
#include "packet.h"


void sc_trace(sc_trace_file *tf, const packet_type& v, const std::string& NAME) {
        
        sc_trace(tf, v.addr, NAME+".addr");
        sc_trace(tf, v.data, NAME+".data");
        sc_trace(tf, v.rw, NAME+".rw");
        sc_trace(tf, v.ack, NAME+".ack");
		sc_trace(tf, v.seq, NAME+".seq");

}

