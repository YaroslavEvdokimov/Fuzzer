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
    Fuzzer( char* in,  char* out) :PathIN(in), PathOUT(out) {}

    Fuzzer() {}

    void Start(const int code_operation);

    void ArgumentsCMD(LPWSTR arguments_convector, std::wstring name_file);

    void InformatioMessage();

    void DelFileConverter() {
        remove("..\\Converter\\ConvertFile\\test2.doc");
        remove("..\\TestFile\\tmp_file.prc");
    }
};