#include "Converter_start.h"

Converter::Converter(std::string Path_entrance, std::string Path_output) {
    this->Path_entrance = Path_entrance;
    this->Path_output = Path_output;
}
std::ifstream::pos_type Converter::filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

void Converter::Start_Converter() {
    std::ifstream File_Entrance(Path_entrance, std::ios_base::in);
    if (!File_Entrance.good())
    {
        std::cerr << "Error input file";
        raise(SIGABRT);
    }
    std::ofstream File_Output(Path_output, std::ios_base::out);
    if (!File_Output.is_open()) {
        std::cerr << "Error output file";
        raise(SIGABRT);
    }
 
    int lenght = filesize("C:/Users/79996/Desktop/Converted/test.prc");
    char* buffer = new char[lenght + 1];
    buffer[lenght] = 0;


    while (!File_Entrance.eof()) {

        File_Entrance.getline(buffer, lenght);
       
        
        if (buffer[2] == 'r') {
           
            
            raise(SIGABRT);
            
            
        }
        File_Output << buffer << std::endl;
    }
}



