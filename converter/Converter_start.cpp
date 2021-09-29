#include "Converter_start.h"

Converter::Converter(std::string path_entrance, std::string path_output) {
    PathEntrance = path_entrance;
    PathOutput = path_output;
}
std::ifstream::pos_type Converter::FileSize(const char* filename){
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

void Converter::StartConverter() {
    std::ifstream file_entrance(PathEntrance, std::ios_base::in);

    if (!file_entrance.good()){
        std::cerr << "Error input file";
        raise(SIGABRT);
    }
    std::ofstream file_output(PathOutput, std::ios_base::out);

    if (!file_output.is_open()) {
        std::cerr << "Error output file";
        raise(SIGABRT);
    }
    int lenght = FileSize("C:/Users/79996/Desktop/Converted/test.prc");
    char* buffer = new char[lenght + 1];
    buffer[lenght] = 0;

    while (!file_entrance.eof()) {
        file_entrance.getline(buffer, lenght);

        if (buffer[2] == 'r') {
            raise(SIGABRT);  
        }
        file_output << buffer << std::endl;
    }
}



