#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <csignal>
#include <string>
#include <vector>
#include <windows.h>

class Generation
{
private:
    char* PathIN;
    char* PathOUT;
    std::ofstream File;
    std::wstring TMPPath;
public:
    Generation() {};

    void GenFile();

    std::wstring TestFile(int);

    std::wstring ModFile(std::wstring);

    char* BitSwap(char*);

    void SetPath(char*, char*);

    void GenTextFile();

    ~Generation() { remove(PathIN); };
};