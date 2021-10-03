#pragma once
#include <iostream>
#include <fstream>
#include <csignal>

class Converter {
private:
    std::string PathEntrance;
    std::string PathOutput;
public:
    Converter(std::string path_entrance, std::string path_output);

    std::ifstream::pos_type FileSize(std::string);
     
    void StartConverter();
};


