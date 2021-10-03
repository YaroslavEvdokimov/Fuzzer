#include <iostream>
#include "ConverterStart.h"

int main(int argc, char* argv[])
{
	Converter con(argv[1], argv[2]);
	con.StartConverter();
	return 0;
}


