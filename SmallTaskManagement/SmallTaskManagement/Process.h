#pragma once

#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>

class Process {
public:
	DWORD processID;
	std::wstring nameExeFile;
	DWORD cntThreads;
	DWORD parentProcessID;
    friend std::wostream& operator<<(std::wostream& out, const Process& proc) {
        out << L"Process ID: " << proc.processID
            << L", Name: " << proc.nameExeFile
            << L", Thread Count: " << proc.cntThreads
            << L", Parent Process ID: " << proc.parentProcessID << std::endl;
        return out;
    }
};
