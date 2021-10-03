#include "ConverterStart.h"

Converter::Converter(std::string path_entrance, std::string path_output) {
    this->PathEntrance = path_entrance;
    this->PathOutput = path_output;
}
std::ifstream::pos_type Converter::FileSize(std::string file_name){
    std::ifstream in(file_name, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

void Converter::StartConverter() {
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
    char buffer;
    while (!file_entrance.eof()) {
        //size_t lenght = 0;
        //file_entrance.read((char*)&lenght, sizeof(lenght));
        //buffer.resize(lenght);
        file_entrance.read((char*)&buffer, sizeof(buffer));
        file_output << buffer;
    }
        file_entrance.close();
        file_output.close();
}



