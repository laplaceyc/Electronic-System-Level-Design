#include "MA_filter.h"
#ifdef __CTOS__
SC_MODULE_EXPORT(MA_filter);
#endif
void MA_filter::prc_MA_filter(){
	 mid0 = 0;  mid1 = 0;  mid2 = 0;  mid3 = 0;
	 mid4 = 0;  mid5 = 0;  mid6 = 0;  mid7 = 0;
	 mid8 = 0;  mid9 = 0; mid10 = 0; mid11 = 0;
	mid12 = 0; mid13 = 0; mid14 = 0; mid15 = 0;
	b0 = (sc_uint<32>)0x00000F0F;
	
	while(1){
	    wait();
		x = input.read();
	    y = ((sc_uint<32>)x + (sc_uint<32>)mid0 + (sc_uint<32>)mid1 + (sc_uint<32>)mid2 + (sc_uint<32>)mid3 + (sc_uint<32>)mid4 + (sc_uint<32>)mid5 + (sc_uint<32>)mid6 + (sc_uint<32>)mid7 + \
			(sc_uint<32>)mid8 + (sc_uint<32>)mid9 + (sc_uint<32>)mid10 + (sc_uint<32>)mid11 + (sc_uint<32>)mid12 + (sc_uint<32>)mid13 + (sc_uint<32>)mid14 + (sc_uint<32>)mid15)*b0;
	    mid15 = mid14; mid14 = mid13; mid13 = mid12; mid12 = mid11;
		mid11 = mid10;	mid10 = mid9;	mid9 = mid8;   mid8 = mid7;
		mid7 = mid6;	 mid6 = mid5;	mid5 = mid4;   mid4 = mid3;
		mid3 = mid2;     mid2 = mid1;   mid1 = mid0;   mid0 =    x;
		output.write(y);
	}
}
