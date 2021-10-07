#include <iostream>
#include "Converter.h"

int main(int argc, char* argv[]){
	if (argc < 3) {
		Converter converter;
		converter.InformatioMessage();
		exit(1);
	}
	Converter convector(argv[1], argv[2]);
	convector.Start();
	return 0;
}


