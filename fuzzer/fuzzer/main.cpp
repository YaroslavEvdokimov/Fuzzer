#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <csignal>
#include "Fuzzer_start.h"

void CatchingSignals(int signum){
    remove("C:\\Users\\79996\\Desktop\\Converted\\test.prc");
    signal(signum, SIG_DFL);
}

int main(){
    setlocale(LC_ALL, "Ru");
    srand(time(NULL));
    signal(SIGABRT, CatchingSignals);
    signal(SIGSEGV, CatchingSignals);
    signal(SIGTERM, CatchingSignals);

    int code_operation = 2;
    std::cout << "Enter code operation: \n 1 - Generation new file \n 2 - Take a test file" << std::endl;
    std::cin >> code_operation;

    while (code_operation == 1 || code_operation == 2){
       if (code_operation == 1){
          char path_in[] = "..\\GenerationTestFile\\test.prc";
          char path_out[] = "..\\GenerationTestFile\\test2.doc";
          Fuzzer fuzzer(path_in, path_out);
          fuzzer.StartFuzzer(1);
       }
       else if (code_operation == 2) {
          char path_in[] = "..\\TestFile\\test.prc";
          char path_out[] = "..\\GenerationTestFile\\test2.doc";
          Fuzzer fuzzer(path_in, path_out);
          fuzzer.StartFuzzer(2);
       }
       else {
          std::cerr << "You entered the wrong code!" << std::endl;
       }
    }
    std::cout << "Finish!";
    return 0;
}


