#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "Generation_start.h"
#include "Create_Log_File.h"
#include <processthreadsapi.h>
#include <winbase.h>

class Fuzzer {
private:
   char *PathIN;
   char *PathOUT;
public:
    Fuzzer(char *PathIN, char *PathOUT) {
        this->PathIN = PathIN;
        this->PathOUT = PathOUT;
    }
    void Start_Fuzzer();
   
    void Del_File_Converter() { remove("C:\\Users\\79996\\Desktop\\Converted\\test2.doc"); }
};

