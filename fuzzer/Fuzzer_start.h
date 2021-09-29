#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "Generation_start.h"
#include "Create_Log_File.h"

class Fuzzer {
private:
   char *PathIN;
   char *PathOUT;
   char PathTestFile;
public:
    Fuzzer(char *in, char *out) {
       PathIN = in;
       PathOUT = out;
    }
    void StartFuzzer(int);
   
    void DelFileConverter() { remove("..\\Converter\\ConvertFile\\test2.doc"); }
};

