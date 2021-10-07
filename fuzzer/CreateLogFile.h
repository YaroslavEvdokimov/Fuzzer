#pragma once
#include <fstream>
#include <string>
#include <iostream>

class CreateLogFile {
private:
    int Counter = 0;
public:
    CreateLogFile() {};

    int LogFile(const std::wstring path_name);

    bool CheckCreateFile(const char* path_log);
};