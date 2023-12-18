#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
void deleteStudentsWithMarks2(const string& file);
void addStudentsToFile(const string& file, int num);

struct Student {
    string lastName, firstName, phoneNumber;
    int mathMarks, Grade, physicsMarks, ukrainianMarks, literatureMarks;
};

int main() {
    const string file = "students.txt";

    int AmountOfStudents;
    cout << "Enter amount of students: ";
    cin >> AmountOfStudents;

    addStudentsToFile(file, AmountOfStudents);

    deleteStudentsWithMarks2(file);

    return 0;
}

void deleteStudentsWithMarks2(const string& file) {
    ifstream reading(file);
    if (!reading.is_open()){
        cerr << "Error opening fila";
        return;
    }

    vector<Student> students;
    Student a;

    while (reading >> a.lastName >> a.firstName >>
           a.Grade >> a.phoneNumber >> a.mathMarks >>
           a.physicsMarks >> a.ukrainianMarks >> a.literatureMarks) {
        if (a.mathMarks != 2 && a.physicsMarks != 2 &&
            a.ukrainianMarks != 2 && a.literatureMarks != 2) {
            students.push_back(a);
        }
    }

    reading.close();

    ofstream writing(file);

    for (auto& b : students) {
        writing << b.lastName << " " << b.firstName << endl
                << b.Grade << endl << b.phoneNumber << endl << b.mathMarks << " "
                << b.physicsMarks << " " << b.ukrainianMarks << " " << b.literatureMarks << endl;
    }

    writing.close();
}

void addStudentsToFile(const string& file, int num) {
    ofstream writing(file, ios::app); 
    // ios::app відкриття для дозапису в кінець файлу

    if (!writing.is_open()){
        cerr << "Error opening fila";
        return;
    }

    for (int i = 0; i < num; ++i) {
        Student n;
        cout << "Enter Last Name: ";
        cin >> n.lastName;
        cout << "Enter First Name: ";
        cin >> n.firstName;
        cout << "Enter Grade: ";
        cin >> n.Grade;
        cout << "Enter Phone Number: ";
        cin >> n.phoneNumber;
        cout << "Enter Math Marks: ";
        cin >> n.mathMarks;
        cout << "Enter Physics Marks: ";
        cin >> n.physicsMarks;
        cout << "Enter Ukrainian Marks: ";
        cin >> n.ukrainianMarks;
        cout << "Enter Literature Marks: ";
        cin >> n.literatureMarks;

        writing << n.lastName << " " << n.firstName << endl << n.Grade << endl 
                << n.phoneNumber << endl << n.mathMarks << " "
                << n.physicsMarks << " " << n.ukrainianMarks << " " << n.literatureMarks << endl;
    }

    writing.close();
}