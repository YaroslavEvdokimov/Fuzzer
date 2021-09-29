#include "Converter_start.h"

Converter::Converter(std::string path_entrance, std::string path_output) {
    this->PathEntrance = path_entrance;
    this->PathOutput = path_output;
}
std::ifstream::pos_type Converter::FileSize(const char* file_name){
    std::ifstream in(file_name, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

void Converter::StartConverter() {
    std::ifstream file_entrance(PathEntrance, std::ios_base::binary | std::ios_base::in);
    if (!file_entrance.good()){
        std::cerr << "Error input file";
        raise(SIGABRT);
    }
    std::ofstream file_output(PathOutput, std::ios_base::binary | std::ios_base::out);
    if (!file_output.is_open()) {
        std::cerr << "Error output file";
        raise(SIGABRT);
    }
    char buffer;
    while(file_entrance.read(&buffer, sizeof(char))){
        file_output << buffer;
        if (buffer = 'r') {
            raise(SIGABRT);
        }
    }
    file_output.close();
}



