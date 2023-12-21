#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student 
{
    string surname;
    string name;
    string patronymic;
    int birthYear;
    int entranceExamScores[3];
    double averageScore;
};
double averageRate(const int *arr)
{
    double s=0;
    for(int i = 0;i<3;i++)
    {
        s+=arr[i];
    }
    return s/3;
}
void writeStrFile(ofstream &inFile, const string &str)
{
    size_t size = str.size();
    inFile.write((char *)&size, sizeof(size));
    inFile.write(str.c_str(), size);
}
void writeStrFile(ofstream &inFile, const int &i)
{
    string str = to_string(i);
    size_t size = sizeof(str);
    inFile.write((char *)&size, sizeof(size));
    inFile.write(str.c_str(), size);
}
void writeStrFile(ofstream &inFile, const double &db)
{
    string str = to_string(db);
    size_t size = sizeof(str);
    inFile.write((char *)&size, sizeof(size));
    inFile.write(str.c_str(), size);
}

string readFile(ifstream &outFile)
{
    size_t size;
    outFile.read((char *)&size, sizeof(size));
    string str(size,' ');
    outFile.read(&str[0], size);
    return str;
}

void writeFile(const vector <Student> &students, const string &filename)
{
    ofstream inFile(filename, ios::binary);

    if (!inFile)
    {
        cout << "Cannot open file.\n";
        return;
    }
    for (const Student &student : students)
    {
        writeStrFile(inFile, student.surname);
        writeStrFile(inFile, student.name);
        writeStrFile(inFile, student.patronymic);
        writeStrFile(inFile, student.birthYear);
        writeStrFile(inFile, student.averageScore);
    }
    inFile.close();
}

vector<Student> readFile(const string &filename)
{
    ifstream outFile(filename, ios::binary);
    if (!outFile)
    {
        cout << "Cannot open file.\n";
        return {};
    }
    vector<Student> students;
    while (outFile.peek() != EOF)
    {
        Student student;
        student.surname = readFile(outFile);
        student.name = readFile(outFile);
        student.patronymic = readFile(outFile);
        student.birthYear = stoi(readFile(outFile));
        student.averageScore = stod(readFile(outFile));
        students.push_back(student);
    }
    outFile.close();
    return students;
}
void addElement(vector<Student> &students, const Student& newStudent, const std::string& surname) 
{
    vector<Student> tempStudents;
    for(int i = 0; i < students.size(); i++)
    {
        tempStudents.push_back(students[i]);
        if (students[i].surname == surname) 
        {
            tempStudents.push_back(newStudent);
        }
    }
    students = tempStudents;
}

void deleteElement( vector<Student> &students, int index) 
{
    Student student;
    students.erase(students.begin() + index);
}
void outputStudents(const vector<Student> &students)
{
    for(const Student &student : students)
    {
        cout<<student.surname<< " " <<student.name<< " " <<student.patronymic<< " " <<student.birthYear<< " " <<student.averageScore<<"\n";;
    }
}
int main() 
{
    string surnameToAdd;
    Student student;
    std::vector<Student> students = {
        {"Ivanov", "Ivan", "Ivanovich", 2000, {200, 181, 179},186},
        {"Petrov", "Petr", "Petrovich", 2001, {156, 135, 167},154.1304},
        {"Sidorov", "Sidor", "Sidorovich", 2002, {200, 195, 193},197}
    };
    std::string filename = "students.bin";
    cout<<"\nInitial students list\n";
    writeFile(students, "students.bin");
    outputStudents(students);
    students = readFile("students.bin");
    cout<<"\nAdding new student after certein surname\n";
    string surname = "Ivanov";
    Student newStudent = {"Sirenko","Yurii","Ser", 2006,{200, 200, 200},200};
    addElement(students, newStudent, surname);
    writeFile(students, "students.bin");
    outputStudents(students);
    cout<<"\nDeliting 2nd student\n";
    deleteElement(students, 2-1);
    writeFile(students, "students.bin");
    outputStudents(students);
    cout<<"\nAdding 2 new students after certein surname\n";
    surname = "Petrov";
    newStudent = {"Schur","Petro","Opanasovuch", 1978,{300, 300, 300},300};
    addElement(students, newStudent, surname);
    surname = "Sidorov";
    newStudent = {"Starostiv","Dmytro","Romanovuch", 2008,{187, 120, 130},152.23};
    addElement(students, newStudent, surname);
    writeFile(students, "students.bin");
    outputStudents(students);
    cout<<"\nDeliting 3rd student\n";
    deleteElement(students, 3-1);
    writeFile(students, "students.bin");
    outputStudents(students);
}