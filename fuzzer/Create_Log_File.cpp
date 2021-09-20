#include "Create_Log_File.h"


int Create_Log_File::Log_File()
{

    char Name_File[] = "C:\\Users\\79996\\Desktop\\Converted\\test.prc";
    char Name_Log_File[] = "C:\\Users\\79996\\Desktop\\Converted\\Log_File.prc";

    std::string filename = "Log_file" + std::to_string(++counter) + ".prc";
    std::string PathFile = "C:\\Users\\79996\\Desktop\\Converted\\";

   
    while(true){
        std::string filename = "Log_file" + std::to_string(++counter) + ".prc";
        std::string tmp = PathFile + filename;
        const char* New_File = tmp.c_str();
        if (CheckLogFile(Name_Log_File) == false) {
           rename(Name_File, Name_Log_File);
           return 0;
         }
        else if (CheckLogFile(New_File) == false) {
           
           rename(Name_File, New_File);
           return 0;
         }
    }
   // MessageBoxA(NULL, "File error", "Fuzzer", NULL);
}

bool Create_Log_File::CheckLogFile(const char *Path_Log) {
    std::ifstream LogFile;
    LogFile.open(Path_Log);
    if (!LogFile) {
        return false;
    }
    else {
        LogFile.close();
        return true;
    }

      
}