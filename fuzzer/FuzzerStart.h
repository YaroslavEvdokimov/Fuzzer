#pragma once
#include <conio.h>
#include "GenerationStart.h"
#include "CreateLogFile.h"

class Fuzzer {
private:
    char* PathIN;
    char* PathOUT;
    char PathTestFile;
public:
    Fuzzer(char* in, char* out) {
        PathIN = in;
        PathOUT = out;
    }
    void StartFuzzer(int);

    void ArgumentsCMD(LPWSTR, std::wstring);

    void DelFileConverter() { remove("..\\Converter\\ConvertFile\\test2.doc"); }
};