// pakcet.h file
#ifndef		PACKETINC
#define		PACKETINC
#include "systemc.h"
class packet_type {
public:
    long info;
    int  seq;
    int  retry;

    packet_type()
        : info(0), seq(0), retry(0) {}
    packet_type( long info_, int seq_, int retry_ )
        : info(info_), seq(seq_), retry(retry_) {}
    packet_type( const packet_type& a )
        : info( a.info ), seq(a.seq), retry(a.retry) {}
    ~packet_type() {}

    packet_type& operator = ( const packet_type& a ) {
        info = a.info;
        seq = a.seq;
        retry = a.retry;
        return *this;
    }
    void print( ostream& os ) const {
        os << info << ", " << seq << ", " << retry << endl;
    }
	friend bool 
    operator == ( const packet_type& a, const packet_type& b ) {
        return ( a.info == b.info &&
                 a.seq == b.seq &&
                 a.retry == b.retry );
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
