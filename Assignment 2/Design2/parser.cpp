// parser.cpp
#include "parser.h"

void parser::prc_parser(){
	unsigned int z;
	if(inFile >> hex >> z){
	//	cout << "parser File success\n";
	}
	else{
		cout << "Warning: End of File \n";
		z = 0;
	}
	x = z;
	output.write(x);
	y = input.read();
	cout << "At time "<< sc_time_stamp() << "::X: " << x << " Y: " << (y >> 16) << endl;
	return;
}