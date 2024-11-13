#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void runProcess(const string& command) {
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcessA(NULL, (LPSTR)command.c_str(), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        cerr << "Failed to create process: " << command << endl;
        return;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

int main() {
    string binaryFileName;
    int recordCount;

    cout << "Enter binary file name: ";
    cin >> binaryFileName;
    cout << "Enter number of records: ";
    cin >> recordCount;

    runProcess("creator.exe " + binaryFileName + " " + to_string(recordCount));

    cout << "Contents of " << binaryFileName << ":" << endl;
    runProcess("type " + binaryFileName);

    string reportFileName;
    double hourlyRate;

    cout << "Enter report file name: ";
    cin >> reportFileName;
    cout << "Enter hourly rate: ";
    cin >> hourlyRate;

    runProcess("reporter.exe " + binaryFileName + " " + reportFileName + " " + to_string(hourlyRate));

    cout << "Report generated in " << reportFileName << ":" << endl;
    runProcess("type " + reportFileName);

    return 0;
}