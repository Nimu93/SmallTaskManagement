#include <iostream>

#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include <system_error>
#include "Process.h"
#include <sstream>
#include <string>

std::string getLastErrorInString() {
    std::ostringstream stream;
    stream << GetLastError();
    return stream.str();

}

std::vector<Process> loadAllProcess() {
    std::vector<Process> vector;
    auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pe;
    if (snapshot == INVALID_HANDLE_VALUE) {
        throw std::system_error(EDOM, std::generic_category(), getLastErrorInString());
    }
    pe.dwSize = sizeof(PROCESSENTRY32);
    if (!Process32First(snapshot, &pe)) {
        CloseHandle(snapshot);
        throw std::system_error(EDOM, std::generic_category(), getLastErrorInString());
    }
    do {
        Process p = { pe.th32ProcessID, pe.szExeFile, pe.cntThreads, pe.th32ParentProcessID };
        vector.push_back(p);
    } while (Process32Next(snapshot, &pe));
    CloseHandle(snapshot);
    return vector;
}

int main()
{
    std::vector<Process> processes = loadAllProcess();
    for (auto &p : processes) {
        std::wcout << p;
    }
    return 0;
}

