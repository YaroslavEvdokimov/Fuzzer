#pragma once
#include <iostream>
#include <fstream>
#include <csignal>
#include <vector>

class Converter {
private:
    std::string PathEntrance;
    std::string PathOutput;
    std::vector<std::uint8_t> BinaryText;
public:
    Converter(std::string path_entrance, std::string path_output);

    std::ifstream::pos_type FileSize(std::string);
     
    void StartConverter();
};


