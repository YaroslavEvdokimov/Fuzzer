#pragma once
#include <iostream>
#include <fstream>
#include <csignal>

class Converter {
private:
    std::string Path_entrance;
    std::string Path_output;
public:
    Converter(std::string path_entrance, std::string path_output);

    std::ifstream::pos_type FileSize(const char*);
     
    void StartConverter();
};


