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
    std::vector<char> buffer;
public:
    Generation() {};

    void GenFile();

    std::wstring TestFile(int num_file);

    std::wstring ModFile(std::wstring file_name);

    void BitSwap(std::vector<char>& buffer);

    void SetPath(const char* in, const char* out);

    void GenBinaryFile();

    ~Generation() { remove(PathIN); };
};
