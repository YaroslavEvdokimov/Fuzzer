#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <csignal>
class Generation
{
private:
    char* PathIN;
    char* PathOUT;
    FILE* File;
    

public:
    Generation() {};

    void Gen_File();

    void set_Path(char*, char*);

    void Gen_text_file();
   
    ~Generation() { remove(PathIN); };
};