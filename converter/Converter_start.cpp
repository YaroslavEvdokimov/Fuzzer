#include "Converter_start.h"

Converter::Converter(std::string Path_entrance, std::string Path_output) {
    this->Path_entrance = Path_entrance;
    this->Path_output = Path_output;
}
std::ifstream::pos_type Converter::filesize(const char* filename){
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

void Converter::Start_Converter() {
    std::ifstream File_Entrance(Path_entrance, std::ios_base::binary | std::ios_base::in);
    if (!File_Entrance.good()){
        std::cerr << "Error input file";
        raise(SIGABRT);
    }
    std::ofstream File_Output(Path_output, std::ios_base::binary | std::ios_base::out);
    if (!File_Output.is_open()) {
        std::cerr << "Error output file";
        raise(SIGABRT);
    }
   
    char buffer;

       while(File_Entrance.read(&buffer, sizeof(char))){
        
        File_Output << buffer;
        if (buffer = 'r') {
            raise(SIGABRT);
        }
    }
        File_Output.close();
}



