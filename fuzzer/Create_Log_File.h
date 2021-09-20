#pragma once
#include <fstream>
#include <string>
#include <iostream>
//#include <WinUser.h>
class Create_Log_File
{
private:
    int counter = 0;
public:
    Create_Log_File() {};

    int Log_File();
  
    bool CheckLogFile(const char* Path_Log);
};

