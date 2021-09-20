#include "Generation_start.h"

void Generation::Gen_File() {
    File = fopen(PathIN, "w");
}

void Generation::Gen_text_file() {

    int Lenght_Word;
    int Lenght_Sentence;
    int Sentence = 0;
    char text;
    char* tmp = &text;

    if (File == NULL) {
        std::cout << "File not found!" << std::endl;
    }

    for (int i = 0; i < 15; ++i) {
        Lenght_Sentence = rand() % 8 + 1;

        for (int SentenceLong = 0; SentenceLong < Lenght_Sentence; ++SentenceLong) {

            Lenght_Word = rand() % 14 + 1;

            for (int j = 0; j < Lenght_Word; ++j) {
                text = (char)(rand() % 20 + 97);

                if (Sentence == 0) {
                    text = (char)toupper(text);
                    fprintf(File, "%c", *tmp);
                    Sentence++;
                }
                else fprintf(File, "%c", *tmp);

            }
            if (Lenght_Sentence != SentenceLong + 1) fputc(' ', File);
        }
        Sentence = 0;
       fputs(". \n", File);

    }
    fclose(File);
}
    void Generation::set_Path(char *IN , char *OUT) {
        PathIN = IN;
        PathOUT = OUT;
}
