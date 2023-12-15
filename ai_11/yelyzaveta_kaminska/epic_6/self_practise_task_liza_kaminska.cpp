#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    double gpa;
};
int main() {
    int numb_students;
    cout << "Enter the number of students: ";
    cin >> numb_students;
    Student* students = new Student[numb_students];
    for (int i = 0; i < numb_students; ++i) {
        cout << "Enter details for student " << (i + 1) << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, students[i].name);
        cout << "Age: ";
        cin >> students[i].age;
        cout << "GPA: ";
        cin >> students[i].gpa;
    }
    cout << endl;
    cout << "Student Information:" << endl;
    for (int i = 0; i < numb_students; ++i) {
        cout << "Student " << (i + 1) << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "GPA: " << students[i].gpa << endl;
    }
    delete[] students;
    return 0;
}
