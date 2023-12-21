#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

constexpr size_t GRADES_COUNT = 3;
struct Student {
    string name;
    string phone_num;
    string group;
    double main_grades[GRADES_COUNT]{};
};

void print_student(const Student& student);
void read(vector<Student>& students, ifstream& file);
void menu(vector<Student>& students);
void write(const vector<Student>& students, ofstream& file);
Student create_student();

constexpr string filename = "students.bin";

int main() {
    vector<Student> students;

    ifstream read_stream(filename, ios::binary);
    if (read_stream.is_open()) {
        read(students, read_stream);
        read_stream.close();
    } else cout << "Starting with empty list." << endl << endl;

    menu(students);

    ofstream output_stream(filename, ios::binary | ios::trunc);
    if (!output_stream.is_open()) {
        cerr << "Error happened when tried to open file." << endl;
        return 1;
    }

    write(students, output_stream);
    output_stream.close();

    return 0;
}

void print_student(const Student& student) {
    cout << "Name: " << student.name << "\n";
    cout << "Phone number: " << student.phone_num << "\n";
    cout << "Group: " << student.group << "\n";
    cout << "Main grades: ";
    for (const double& grade : student.main_grades) {
        cout << grade << " ";
    }
    cout << endl;
}

void read(vector<Student>& students, ifstream& file) {
    Student student;
    while (file >> student.name >> student.phone_num >> student.group) {
        for (double& grade : student.main_grades) {
            file >> grade;
        }
        students.push_back(student);
    }
}

void write(const vector<Student>& students, ofstream& file) {
    for (const Student& student : students) {
        file << student.name << "\n" << student.phone_num << "\n" << student.group << "\n";
        for (const double& grade : student.main_grades) {
            file << grade << " ";
        }
        file << endl;
    }
}

Student create_student() {
    string input_buf;

    Student new_student;
    cout << "Enter name: ";
    getline(cin, new_student.name);
    cout << "Enter phone number: ";
    getline(cin, new_student.phone_num);
    cout << "Enter group: ";
    getline(cin, new_student.group);
    cout << "Enter main grades: ";
    for (double& grade : new_student.main_grades) {
        getline(cin, input_buf);
        grade = stod(input_buf);
    }

    return new_student;
}

void menu(vector<Student>& students) {
    int choice;
    string input;

    do {
        cout << "1. Add student\n"
                "2. Print all students\n"
                "3. Erase student\n"
                "4. Remove students by group\n"
                "5. Add student after another student\n"
                "0. Exit\n"
                "Your choice: ";

        getline(cin, input);
        choice = stoi(input);

        switch (choice) {
            case 1: {
                students.push_back(create_student());
                break;
            }
            case 2: {
                if (students.empty()) {
                    cout << "List is empty!" << endl;
                    break;
                }

                for (int i = 0; i < students.size(); ++i) {
                    cout << i + 1 << "." << endl;
                    print_student(students[i]);
                }
                break;
            }
            case 3: {
                int index;
                cout << "Enter index: ";
                getline(cin, input);
                index = stoi(input);

                if (index < 0 || index >= students.size()) {
                    cout << "Wrong index!\n";
                    break;
                }
                students.erase(students.begin() + index);

                break;
            }
            case 4: {
                string group;
                cout << "Enter group: ";
                getline(cin, group);

                for (auto it = students.begin(); it != students.end(); it++)
                    if (it->group == group) it = students.erase(it);

                break;
            }
            case 5: {
                string name;
                cout << "Enter the name of student in database: ";
                getline(cin, name);

                auto it = students.begin();
                for (; it != students.end(); it++)
                    if (it->name == name) break;

                if (it == students.end()) {
                    cout << "Wrong name!" << endl;
                    break;
                }
                students.insert(it + 1, create_student());

                break;
            }
            case 0:
                break;
            default: {
                cout << "Wrong choice!" << endl;
                break;
            }
        }
    } while (choice != 0);
}
