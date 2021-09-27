#include <iostream>
#include "Converter_start.h"

int main(int argc, char* argv[]){
	setlocale(LC_ALL, "Ru");
	Converter con(argv[1], argv[2]);
	con.StartConverter();
	return 0;
}


