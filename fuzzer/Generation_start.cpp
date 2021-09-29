#include "Generation_start.h"

void Generation::GenFile() {
    File.open(PathIN, std::ios::binary);
}
void Generation::GenTextFile() {
    int lenght_word;
    int lenght_sentence;
    int sentence = 0;
    std::string text;
    char tmp;

    if (!File.is_open()) {
        std::cout << "Cant create a file!" << std::endl;
    }
    for (int i = 0; i < 15; ++i) {
        lenght_sentence = rand() % 8 + 1;

        for (int sentence_long = 0; sentence_long < lenght_sentence; ++sentence_long) {
            lenght_word = rand() % 14 + 1;

            for (int j = 0; j < lenght_word; ++j) {
                text = (char)(rand() % 20 + 97);

                if (sentence == 0) {
                    tmp = text[j];
                    File.write((char*)&text, sizeof(text));
                    sentence++;
                }
                else  File.write((char*)&text, sizeof(text));
            }
            if (lenght_sentence != sentence_long + 1) {
                text = ' ';
                File.write((char*)&text, sizeof(text));
            }
        }
        sentence = 0;
        text = ". ";
        File.write((char*)&text, sizeof(text));
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

    file_test.seekg(0, file_test.end);
    int length = file_test.tellg();
    if (length == 0) {
      return path_tmp_file;
    }
    
    file_test.seekg(0, file_test.beg);
    char* buffer = new char[length];

    while (file_test.getline(buffer, length, '\0')) {
        file_test.read(buffer, length);
        buffer = BitSwap(buffer);
        file_tmp.write(buffer, length);
    }
    file_tmp.close();
    file_test.close();
    delete[] buffer;
    return path_tmp_file;
}

char * Generation::BitSwap(char *buffer) {
    char tmp_symbol;

    int it = rand() % 5 + 1;
    for (int i = 0; i < it; ++i) {
        int bit_one = rand() % 15 + 1;
        int bit_two = rand() % 15 + 1;
        tmp_symbol = buffer[bit_one];
        buffer[bit_one] = buffer[bit_two];
        buffer[bit_two] = tmp_symbol;
    }
    return buffer;
}
void Generation::SetPath(char* in, char* out) {
    PathIN = in;
    PathOUT = out;
}