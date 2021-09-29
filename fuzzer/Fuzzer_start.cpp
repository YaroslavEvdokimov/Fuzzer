#include "Fuzzer_start.h"

void Fuzzer::StartFuzzer(int code_operation) {
    int code = code_operation;
    int tmp_test_file = 0;
    Generation gen;
    gen.SetPath(PathIN, PathOUT);

    while (true) {
       
        
        LPWSTR arguments_convector = 0;
        if (code == 1) {
            gen.GenFile();
            gen.GenTextFile();
            std::wstring name_file = L"..\\GenerationTestFile\\test.prc";
            std::wstring arguments(L"Convector.exe ..\\GenerationTestFile\\test.prc ..\\GenerationTestFile\\test2.doc");
            LPWSTR arguments_convector = &arguments[0];
            ArgumentsCMD(arguments_convector, name_file);
        }
        else if (code == 2) {
            if (gen.TestFile(++tmp_test_file) != L"1") {
               std::wstring name_file = gen.TestFile(tmp_test_file);
               std::wstring name_exe(L"Convector.exe ");
               std::wstring name_path_out(L" ..\\GenerationTestFile\\test2.doc");
               std::wstring arguments = name_exe + name_file + name_path_out;
               LPWSTR arguments_convector = &arguments[0];
               ArgumentsCMD(arguments_convector, name_file);   
            }else  
                tmp_test_file = 0;
            }
        }
        
}

void Fuzzer::ArgumentsCMD(LPWSTR arguments_convector, std::wstring name_file){
    STARTUPINFO process = { 0 };
    PROCESS_INFORMATION pr = { 0 }; 
    DWORD process_code;
    std::wstring path(L"..\\Convector\\Debug\\Convector.exe");
    LPWSTR path_exe = &path[0];
    if (CreateProcess(path_exe, arguments_convector, NULL, NULL, FALSE, NULL, NULL, NULL, &process, &pr) == TRUE) {
        WaitForSingleObject(pr.hProcess, INFINITE);

        if (GetExitCodeProcess(pr.hProcess, &process_code) == true) {
            if (process_code > 0) {
                CloseHandle(pr.hProcess);
                CreateLogFile NewLogFile;
                NewLogFile.LogFile(name_file);
            }
        }
    }
    else {
        std::cout << "Error: " + GetLastError() << std::endl;
        system("pause");
        return;
    }
    DelFileConverter();

        
 }