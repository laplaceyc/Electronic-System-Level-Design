// pakcet.h file
#ifndef		PACKETINC
#define		PACKETINC
#include "systemc.h"
class packet_type {
public:

    sc_uint<32> addr; // The address field
    sc_uint<8> data; // The data field
    bool rw; // 1: Write; 0: Read
    bool ack; // 1: Ack; 0: Nak
	int  seq;

    packet_type()
        : addr(0), data(0), rw(0), ack(0), seq(0){}
    packet_type( sc_uint<32> addr_, sc_uint<8> data_, bool rw_, bool ack_, int seq_ )
        : addr(addr_), data(data_), rw(rw_), ack(ack_), seq(seq_) {}
    packet_type( const packet_type& a )
        : addr( a.addr ), data(a.data), rw(a.rw), ack(a.ack), seq(a.seq) {}
    ~packet_type() {}
    
    packet_type& operator = ( const packet_type& a ) {
        addr = a.addr;
        data= a.data;
        rw = a.rw;
		ack = a.ack;
		seq = a.seq;
        return *this;
    }
    void print( ostream& os ) const {
        os << addr << ", " << data << ", " << rw << ", "<< ack << "," << seq <<endl;
    }
	  friend bool 
    operator == ( const packet_type& a, const packet_type& b ) {
        return ( a.addr == b.addr &&
                 a.data == b.data &&
                 a.rw == b.rw &&
//               a.ack == b.ack &&
				 a.seq == b.seq );
    }
    
    
    friend ostream&
    operator << ( ostream& os, const packet_type& a )
    {
        a.print( os );
        return os;
    }
    
};
extern void sc_trace(sc_trace_file *tf,
                     const packet_type& v,
                     const std::string& name);
#endif
