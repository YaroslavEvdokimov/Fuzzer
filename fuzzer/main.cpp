﻿#include <ctime>
#include "Fuzzer.h"

void CatchingSignals(int signum) {
    remove("..\\GenerationTestFile\\test.prc");
    signal(signum, SIG_DFL);
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    if (argc < 4) {
        Fuzzer fuzzer;
        fuzzer.InformatioMessage();
        exit(1);
    }
    signal(SIGABRT, CatchingSignals);
    signal(SIGSEGV, CatchingSignals);
    signal(SIGTERM, CatchingSignals);

    CreateDirectory(L"..\\GenerationTestFile", NULL);
    CreateDirectory(L"..\\LogFile", NULL);
    CreateDirectory(L"..\\TestFile", NULL);

    int code_operation = std::atoi(argv[3]);
    while (code_operation == 1 || code_operation == 2) {
        if (code_operation == 1) {
            Fuzzer fuzzer(argv[1], argv[2]);
            fuzzer.Start(1);
        }
        else if (code_operation == 2) {
            Fuzzer fuzzer(argv[1], argv[2]);
            fuzzer.Start(2);
        }
        else {
            std::cerr << "You entered the wrong code!" << std::endl;
        }
    }
    std::cout << "Finish!";
    return 0;
}