#include <iostream>
#include <fstream>
#include <cstring>
#include "employee.h"

int main(int argc, char* argv[]) {
    std::string filename = argv[1];
    int numRecords = std::atoi(argv[2]);

    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Failed to create file." << std::endl;
        return 1;
    }

    for (int i = 0; i < numRecords; ++i) {
        employee emp;
        std::cout << "Enter employee number: ";
        std::cin >> emp.num;

        std::cin.ignore();
        std::cout << "Enter employee name: ";
        std::cin.getline(emp.name, 10);

        std::cout << "Enter hours worked: ";
        std::cin >> emp.hours;

        outFile.write(reinterpret_cast<const char*>(&emp), sizeof(employee));
    }

    outFile.close();
    return 0;
}