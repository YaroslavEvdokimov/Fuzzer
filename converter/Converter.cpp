#include "Converter.h"

Converter::Converter(const std::string &path_entrance, const std::string &path_output) 
    : PathEntrance(path_entrance), PathOutput(path_output) {}

Converter::Converter(){}

std::ifstream::pos_type Converter::GetFileSize(const std::string file_name){
    std::ifstream in(file_name, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

void Converter::Start() {
    std::ifstream file_entrance(PathEntrance, std::ios::binary | std::ios::in);
    if (!file_entrance.good()){
        std::cerr << "Error input file";
        raise(SIGABRT);
    }
    std::ofstream file_output(PathOutput, std::ios::out);
    if (!file_output.is_open()) {
        std::cerr << "Error output file";
        raise(SIGABRT);
    }
    int lenght = GetFileSize(PathEntrance);
    if (lenght > 0) {
        BinaryData.resize(lenght + 1);
    }else{
        std::cerr << "There is no file in the destination folder or the file is empty!" << std::endl;
        InformatioMessage();
        exit(1);
    }
    file_entrance.read(reinterpret_cast<char*>(&BinaryData[0]), lenght);
    for (int i = 0; i < BinaryData.size(); ++i) {
        if (BinaryData.size() > 4 || BinaryData[4] == 'R') {
            raise(SIGABRT);
        }
        file_output << BinaryData[i];
    }
}

void Converter::InformatioMessage() {
    std::string tmp_info;
    std::vector<std::string> v_info;
    std::ifstream info_file("..\\Information\\ReadMe.txt", std::ios::in);
    if (info_file.is_open()) {
        std::copy(std::istream_iterator<std::string>(info_file), std::istream_iterator<std::string>(), std::back_inserter(v_info));

        for (auto& a : v_info) {
            tmp_info += a + ' ';
        }

        std::wstring wstr(tmp_info.begin(), tmp_info.end());
        LPCUWSTR str_info = &wstr[0];
        MessageBox(0, str_info, L"Information massage", MB_OK);
    }
}


