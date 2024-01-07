#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employee {
    string lastName;
    string firstName;
    string middleName;
    string position;
    int birthYear;
    double salary;
};

void printEmployee(const Employee& emp) {
    cout << "Прізвище: " << emp.lastName << endl;
    cout << "Ім'я: " << emp.firstName << endl;
    cout << "По батькові: " << emp.middleName << endl;
    cout << "Посада: " << emp.position << endl;
    cout << "Рік народження: " << emp.birthYear << endl;
    cout << "Заробітна плата: " << emp.salary << endl;
}

void createBinaryFile(const string& filename, const Employee* employees, int numEmployees) {
    ofstream file(filename, ios::binary | ios::trunc);

    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу для запису!" << endl;
        return;
    }

    for (int i = 0; i < numEmployees; ++i) {
        file.write(reinterpret_cast<const char*>(&employees[i]), sizeof(Employee));
    }

    file.close();
}

void printBinaryFile(const string& filename) {
    ifstream file(filename, ios::binary);

    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу для читання!" << endl;
        return;
    }

    Employee emp;
    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        printEmployee(emp);
    }

    file.close();
}

void deleteEmployee(const string& filename, const string& lastNameToDelete) {
    ifstream inFile(filename, ios::binary);
    ofstream outFile("temp.bin", ios::binary | ios::trunc);

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Помилка відкриття файлу для читання або запису!" << endl;
        return;
    }

    Employee emp;
    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (emp.lastName != lastNameToDelete) {
            outFile.write(reinterpret_cast<const char*>(&emp), sizeof(Employee));
        }
    }

    inFile.close();
    outFile.close();

    remove(filename.c_str());
    rename("temp.bin", filename.c_str());
}

void addEmployeeAfter(const string& filename, const Employee& newEmployee, int insertAfterIndex) {
    ifstream inFile(filename, ios::binary);
    ofstream outFile("temp.bin", ios::binary | ios::trunc);

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Помилка відкриття файлу для читання або запису!" << endl;
        return;
    }

    Employee emp;
    int currentIndex = 0;

    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        outFile.write(reinterpret_cast<const char*>(&emp), sizeof(Employee));

        if (currentIndex == insertAfterIndex) {
            outFile.write(reinterpret_cast<const char*>(&newEmployee), sizeof(Employee));
        }

        currentIndex++;
    }

    inFile.close();
    outFile.close();

    remove(filename.c_str());
    rename("temp.bin", filename.c_str());
}

int main() {
    const int numEmployees = 3;
    Employee employees[numEmployees] = {
        {"Іванов", "Іван", "Іванович", "Дата Анаітик", 2000, 7000.0},
        {"Петров", "Петро", "Петрович", "Розробник", 2001, 6000.0},
    };

    createBinaryFile("employees.bin", employees, numEmployees);

    cout << "Вміст файлу:" << endl;
    printBinaryFile("employees.bin");

    string lastNameToDelete = "Петров";
    deleteEmployee("employees.bin", lastNameToDelete);

    Employee newEmployee = {"Андрієнко", "Андрій", "Андрійович", "Тестер", 2002, 5000.0};
    int insertAfterIndex = 0;

    addEmployeeAfter("employees.bin", newEmployee, insertAfterIndex);

    cout << "Оновлений вміст файлу:" << endl;
    printBinaryFile("employees.bin");

    return 0;
}