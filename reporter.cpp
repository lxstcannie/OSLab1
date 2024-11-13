#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "employee.h"

int main(int argc, char* argv[]) {
    std::string binaryFileName = argv[1];
    std::string reportFileName = argv[2];
    double hourlyRate = std::atof(argv[3]);

    std::ifstream inFile(binaryFileName, std::ios::binary);
    if (!inFile) {
        std::cerr << "Cannot open binary file!" << std::endl;
        return 1;
    }
    
    std::ofstream reportFile(reportFileName);
    if (!reportFile) {
        std::cerr << "Cannot open report file for writing!" << std::endl;
        return 1;
    }

    reportFile << "Отчет по файлу \"" << binaryFileName << "\"" << std::endl;
    reportFile << "Номер сотрудника  Имя сотрудника  Часы  Зарплата" << std::endl;

    employee emp;
    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(employee))) {
        double salary = emp.hours * hourlyRate;
        reportFile << std::setw(15) << emp.num
            << std::setw(15) << emp.name
            << std::setw(10) << emp.hours
            << std::setw(10) << salary << std::endl;
    }

    inFile.close();
    reportFile.close();

    return 0;
}