#pragma once
#include <conio.h>
#include "Generation.h"
#include "CreateLogFile.h"

class Fuzzer {
private:
    char* PathIN;
    char* PathOUT;
    char PathTestFile;
public:
    Fuzzer(const char* in, const char* out)
    :PathIN (in), PathOUT(out){}
    
    void Start(const int code_operation);

    void ArgumentsCMD(LPWSTR arguments_convector, std::wstring name_file);

    void DelFileConverter() { 
        remove("..\\Converter\\ConvertFile\\test2.doc");
        remove("..\\TestFile\\tmp_file.prc");
    }
};
