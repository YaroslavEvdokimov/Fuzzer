#include "GenerationStart.h"

void Generation::GenFile() {
    File.open(PathIN, std::ios::binary);
}
void Generation::GenTextFile() {
    int lenght_word;
    int lenght_sentence;
    int sentence = 0;
    std::string text;
    size_t lenght;
    char tmp;

    if (!File.is_open()) {
        std::cout << "Cant create a file!" << std::endl;
    }
    for (int i = 0; i < 15; ++i) {
        lenght_sentence = rand() % 8 + 1;
        for (int sentence_long = 0; sentence_long < lenght_sentence; ++sentence_long) {
            lenght_word = rand() % 14 + 1;
            for (int j = 0; j < lenght_word; ++j) {
                tmp = (char)(rand() % 20 + 97);
                if (sentence == 0) {
                    text += tmp;
                    sentence++;
                }
                else text += tmp;
            }
            if (lenght_sentence != sentence_long + 1) {
                tmp = ' ';
                text += tmp;
            }
        }
        sentence = 0;
        tmp = '.';
        text += tmp;
        lenght = text.size();
        File.write((char*)&lenght, sizeof(lenght));
        File.write((char*)&text[0], lenght);
    }
    File.close();
}

std::wstring Generation::TestFile(int num_file) {
    int counter = num_file;
    int number = 0;
    std::wstring file_name;
    std::wstring file_tmp;
    WIN32_FIND_DATA find_file_data;
    HANDLE hf;
    hf = FindFirstFile(L"..\\TestFile\\*.prc", &find_file_data);
    if (hf != INVALID_HANDLE_VALUE) {
        do {
            ++number;
            if (counter == number) {
                file_name = find_file_data.cFileName;
                FindClose(hf);
                file_tmp = ModFile(file_name);
                return file_tmp;
            }
        } while (FindNextFile(hf, &find_file_data) != 0);
        FindClose(hf);
    }
    file_tmp = L"1";
    return file_tmp;
}

std::wstring Generation::ModFile(std::wstring file_name) {
    char tmp;
    std::wstring path_file = L"..\\TestFile\\" + file_name;
    std::ifstream file_test(path_file, std::ios_base::binary | std::ios::in);
    if (!file_test.is_open()) {
        std::cout << "Unable to open file!" << std::endl;
    }
    std::wstring path_tmp_file = L"..\\TestFile\\tmp_file.prc";
    std::ofstream file_tmp(path_tmp_file, std::ios_base::binary | std::ios::out);
    if (!file_tmp.is_open()) {
        std::cout << "Unable to open file!" << std::endl;
    }
    while (!file_test.eof()) {
        file_test.read((char *)&tmp, sizeof(char));
        buffer.push_back(tmp);
    }
    BitSwap(buffer);
    for (auto tmp : buffer) {
        file_tmp.write((char *)&tmp, sizeof(char));
    }
    buffer.clear();
    file_tmp.close();
    file_test.close();
    return path_tmp_file;
}
    void Generation::BitSwap(std::vector<char> &buffer) {
    char tmp_symbol;
    int it = rand() % 5 + 1;
    for (int i = 0; i < it; ++i) {
        int bit_one = rand() % buffer.size()-1 + 1;
        int bit_two = rand() % buffer.size()-1 + 1;
        std::swap(buffer[bit_one], buffer[bit_two]);
    }
}
void Generation::SetPath(char* in, char* out) {
    PathIN = in;
    PathOUT = out;
}