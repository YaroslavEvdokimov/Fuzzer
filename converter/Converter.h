#pragma once
#include <iostream>
#include <fstream>
#include <csignal>
#include <vector>
#include <windows.h>

class Converter {
private:
    std::string PathEntrance;
    std::string PathOutput;
    std::vector<std::uint8_t> BinaryData;
public:
    Converter();

    Converter(const std::string path_entrance, const std::string path_output);

    std::ifstream::pos_type GetFileSize(const std::string file_name);
     
    void Start();

    void InformatioMessage();
};


