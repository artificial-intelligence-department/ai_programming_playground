#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student {
    char lastName[50];
    char firstName[50];
    char middleName[50];
    char grade;
    char phoneNumber[20];
    char grades[4];
};

bool hasFailingGrade(const Student& student) {
    for (int i = 0; i < 4; ++i) {
        if (student.grades[i] == '2') {
            return true;
        }
    }
    return false;
}

void addStudentsToFile(const char* filename, int numStudents) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cout << "Error opening the file!" << endl;
        return;
    }

    for (int i = 0; i < numStudents; ++i) {
        Student newStudent;
        cout << "Enter details of student " << i + 1 << ":" << endl;
        cout << "Last Name: ";
        cin.ignore();
        cin.getline(newStudent.lastName, 50);
        cout << "First Name: ";
        cin.getline(newStudent.firstName, 50);
        cout << "Middle Name: ";
        cin.getline(newStudent.middleName, 50);
        cout << "Grade: ";
        cin >> newStudent.grade;
        cin.ignore();
        cout << "Phone Number: ";
        cin.getline(newStudent.phoneNumber, 20);
        cout << "Grades for subjects (Math, Physics, Ukrainian, Literature): ";
        for (int j = 0; j < 4; ++j) {
            cin >> newStudent.grades[j];
        }
        file.write(reinterpret_cast<const char*>(&newStudent), sizeof(Student));
    }

    file.close();
}

void removeStudentsWithFailingGrade(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cout << "Error opening the file!" << endl;
        return;
    }

    ofstream tempFile("temp.dat", ios::binary);

    while (file.peek() != EOF) {
        Student student;
        file.read(reinterpret_cast<char*>(&student), sizeof(Student));
        if (!hasFailingGrade(student)) {
            tempFile.write(reinterpret_cast<const char*>(&student), sizeof(Student));
        }
    }

    file.close();
    tempFile.close();

    remove(filename);
    rename("temp.dat", filename);
}

void displayStudentsWithGrades(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cout << "Error opening the file!" << endl;
        return;
    }

    cout << "Students who do not have any failing grades:" << endl;
    while (file.peek() != EOF) {
        Student student;
        file.read(reinterpret_cast<char*>(&student), sizeof(Student));
        if (!hasFailingGrade(student)) {
            cout << "Last Name: " << student.lastName << endl;
            cout << "First Name: " << student.firstName << endl;
            cout << "Middle Name: " << student.middleName << endl;
            cout << "Grade: " << student.grade << endl;
            cout << "Phone Number: " << student.phoneNumber << endl;
            cout << "Grades for subjects (Math, Physics, Ukrainian, Literature): ";
            for (int j = 0; j < 4; ++j) {
                cout << student.grades[j] << " ";
            }
            cout << endl;
        }
    }

    file.close();
}

int main() {
    const char* filename = "student.dat";
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore();

    addStudentsToFile(filename, numStudents);
    removeStudentsWithFailingGrade(filename);
    displayStudentsWithGrades(filename);

    return 0;
}
