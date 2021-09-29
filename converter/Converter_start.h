#pragma once
#include <iostream>
#include <fstream>
#include <csignal>

class Converter {
private:
    std::string PathEntrance;
    std::string PathOutput;
public:
    Converter(std::string, std::string);

    std::ifstream::pos_type FileSize(const char*);
     
    void StartConverter();
};


