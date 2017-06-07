// FA.cpp
#include "FA.h"
#ifdef __CTOS__
SC_MODULE_EXPORT(FA);
#endif

void FA::prc_cout(){
	Cout = c1 | c2;
}
