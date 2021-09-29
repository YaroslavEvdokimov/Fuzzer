#include "Create_Log_File.h"

int CreateLogFile::LogFile(std::wstring path_name) {
    std::string tmp(path_name.begin(), path_name.end());
    const char* name_file = tmp.c_str();
    char name_log_file[] = "..//LogFile//Log_File.prc";
    std::string path_file = "..//LogFile//";

    while (true) {
        std::string file_name = "Logfile" + std::to_string(++Counter) + ".prc";
        std::string tmp = path_file + file_name;
        const char* new_file = tmp.c_str();
        if (CheckCreateFile(name_log_file) == false) {
            rename(name_file, name_log_file);
            return 0;
        }
        else if (CheckCreateFile(new_file) == false) {
            rename(name_file, new_file);
            return 0;
        }
    }
}

bool CreateLogFile::CheckCreateFile(const char* path_log) {
    std::ifstream log_file;
    log_file.open(path_log);
    if (!log_file) {
        return false;
    }
    else {
        log_file.close();
        return true;
    }
}