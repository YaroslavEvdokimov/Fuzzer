#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <csignal>
#include "Fuzzer_start.h"


void catching_signals(int signum)
{
    remove("C:\\Users\\79996\\Desktop\\Converted\\test.prc");
    signal(signum, SIG_DFL);

}


int main()
{
    srand(time(NULL));
    signal(SIGABRT, catching_signals);
    signal(SIGSEGV, catching_signals);
    signal(SIGTERM, catching_signals);

    char PathIN[] = "C:\\Users\\79996\\Desktop\\Converted\\test.prc";
    char PathOUT[] = "C:\\Users\\79996\\Desktop\\Converted\\test2.doc";

    Fuzzer fuzzer(PathIN, PathOUT);
    fuzzer.Start_Fuzzer();
    std::cout << "Finish!";
    return 0;
}


