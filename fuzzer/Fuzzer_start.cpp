#include "Fuzzer_start.h"

void Fuzzer::Start_Fuzzer() {

    Generation gen;
    gen.set_Path(PathIN, PathOUT);

    while (true) {
    
        gen.Gen_File();
        gen.Gen_text_file();
        STARTUPINFO process = {0};
        PROCESS_INFORMATION pr = {0};
        std::wstring Path (L"C:\\Users\\79996\\source\\repos\\Convector\\Debug\\Convector.exe");
        std::wstring Arguments(L"Convector.exe C:\\Users\\79996\\Desktop\\Converted\\test.prc C:\\Users\\79996\\Desktop\\Converted\\test2.doc");
        LPWSTR PathExe = &Path[0];
        LPWSTR ArgumentsConvector = &ArgumentsConvector[0];
      
        DWORD ProcessCode;
        if (CreateProcess(PathExe, ArgumentsConvector, NULL, NULL, FALSE, NULL, NULL, NULL, &process, &pr) == TRUE) {
           
            WaitForSingleObject(pr.hProcess, INFINITE);
            if (GetExitCodeProcess(pr.hProcess, &ProcessCode) == true) 
            {
                
                if (ProcessCode > 0) {
                    Create_Log_File LogFile;
                    LogFile.Log_File();
                }
                CloseHandle(pr.hProcess); 
            } 
        } else {
            std::cout << "Error: " + GetLastError() << std::endl;
            system("pause");
            return ;
        
        }
        
        Del_File_Converter();
    }
}


