#include <iostream>
#include "Converter_start.h"

int main(int argc, char* argv[])
{
	
	Converter con(argv[1], argv[2]);
		//Converter con("C:\\Users\\79996\\Desktop\\Converted\\test.prc", "C:\\Users\\79996\\Desktop\\Converted\\test2.doc");
	con.Start_Converter();
	return 0;
}


