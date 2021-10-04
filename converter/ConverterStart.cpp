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
    std::uint8_t buffer;
    while (!file_entrance.eof()) {
        file_entrance.read((char*)&buffer, sizeof(buffer));
        BinaryText.push_back(buffer);  
    }
    for (int i = 0; i < BinaryText.size(); ++i) {
        if (BinaryText[4] == 'R') {
            raise(SIGABRT);
        }
        file_output << BinaryText[i];
    }
    file_entrance.close();
    file_output.close();
}



