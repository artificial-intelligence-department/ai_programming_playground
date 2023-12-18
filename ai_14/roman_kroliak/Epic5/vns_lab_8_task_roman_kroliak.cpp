#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct employee {
    string name;
    string middleName;
    string lastname;
    string position;
    int bYear{};
    int salary{};
};

void printEmployee(const employee& a){
    cout << "Name: " << a.name << endl;
    cout << "Middle name: " << a.middleName << endl;
    cout << "Lastname: " << a.lastname << endl;
    cout << "Position: " << a.position << endl;
    cout << "Birth year: " << a.bYear << endl;
    cout << "Salary: " << a.salary << "$\n\n";
}

void createFile (const string& filename, employee cos[], int n){
    ofstream file(filename, ios::binary | ios:: trunc);
    if (file.is_open()) {
        for (int i = 0; i < n; ++i) {
            file.write((char*)& cos[i], sizeof(employee));
        }
        file.close();
    }
    else cout << "Error! File cannot be opened!" << endl;
}

void readFile (const string& filename){
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
        employee temp;
        while(file.read((char*)& temp, sizeof(employee))){
            printEmployee(temp);
        }
        file.close();
    }
    else cout << "Error! File cannot be opened!" << endl;
}

void fireEmployee (const string& filename, const string& lastname){
    ofstream newFile("temp.bin", ios::binary | ios:: trunc);
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
        employee temp;
        while(file.read((char*)& temp, sizeof(employee))){
            if(temp.lastname != lastname) newFile.write((char*)& temp, sizeof(employee));
        }
        file.close();
        newFile.close();
        remove(filename.c_str());
        rename("temp.bin", filename.c_str());
    }
    else cout << "Error! File cannot be opened!" << endl;
}

void hireEmployeeAt (const string& filename, int n, const employee& a){
    ofstream newFile("temp.bin", ios::binary | ios:: trunc);
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
        employee temp;
        int i = 0;
        while (file.read((char*)&temp, sizeof(employee))) {
            newFile.write((char*)&temp, sizeof(employee));
            if (i == n) {
                newFile.write((char*)&a, sizeof(employee));
            }
            i++;
        }
        file.close();
        newFile.close();
        remove(filename.c_str());
        rename("temp.bin", filename.c_str());
    }
    else cout << "Error! File cannot be opened!" << endl;
}

int main() {
    employee employees[] = {
            {"Dallas", "Marion", "Patterson", "Data scientist", 1999, 3000},
            {"Pavlina", "Puck", "Stewart", "C++ Developer", 2001, 4000},
            {"Nicholas", "Riley", "West", "Project manager", 2000, 2000}
    };
    int employeesNum = sizeof(employees)/sizeof(employee);
    string filename = "employees.bin";
    createFile(filename, employees, employeesNum);
    cout << "The initial content of the file:\n";
    readFile(filename);
    fireEmployee(filename, "Patterson");
    employee newEmp = {"Sebastian", "Halifax", "Murphy", "Data analyst", 1998, 2700};
    hireEmployeeAt(filename, 0, newEmp);
    cout << "The modified content of the file:\n";
    readFile(filename);
    return 0;
}
