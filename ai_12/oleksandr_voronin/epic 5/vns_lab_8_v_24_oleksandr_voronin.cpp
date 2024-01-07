#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

double avarageGrades= 3 ;
struct Student
{
    string name;
    string number;
    string group;
    double grades[3];
};

void printStudent(const vector<Student>& students){
    for (const Student& student : students) {
    cout << "Name "<< student.name <<endl;
    cout << "Phone number "<<student.number<< endl;
    cout << "group "<<student.group<<endl;
    cout << "Grades "<<endl;
    for (const double& grade : student.grades){
        cout << grade<<" ";
    }
    cout << " "<<endl;
    cout << "-----------------------" << endl;
    }
}

void PrintStudentsinFile(const vector<Student>& students, const string& filename){
    ofstream file;
file.open("Students.bin");
file.is_open();
if(!file.is_open()){
    cout << "ERROR"<<endl;
    
}
 for (const Student& student : students){
    file << "Name "<< student.name <<endl;
    file << "Phone number "<<student.number<< endl;
    file << "group "<<student.group<<endl;
    file << "Grades "<<endl;
    for (const double& grade : student.grades){
        file << grade<<" ";
    }
    file << " "<<endl;
 }
file.close();
}

void DeleteformFIle(vector<Student>& students,const string &group, double minAverage){
     ifstream inFile("Students.bin");

    if (!inFile.is_open())
    {
        cout << "ERROR" << endl;
        return;
    }

    string line;
    while (getline(inFile, line))
    {
        Student student;
        inFile >> student.name >> student.number >> student.group;
        for (int i = 0; i < 3; ++i)
        {
            inFile >> student.grades[i];
        }

        double sum = 0;
        for (double grade : student.grades)
        {
            sum += grade;
        }
        double average = sum / 3;
        for (auto it = students.begin(); it != students.end(); it++){
        if (it->group == group)
        {
            if(average<avarageGrades)
            {
                students.erase(it);
            }
        }
        }
    }

    inFile.close();
    

}

int main(){
vector<Student> students{
{"Olexandr Oleksandrovych Voronin","9643433215","SHI-12",{5,3.5,3}},
{"Volodymyr Volodymyrovych Dashavski","968526076","SHI-12",{3,3,3}},
{"Dmytro Dmytrovych Sydor","974343615","SHI-12",{3.5,4,5}},
{"Anton Antonov Antan","956323615","SHI-11",{3.5,4,5}},
{"Ivan Ivasik Telesik","956321122","SHI-11",{3.5,2,2}}
};
printStudent(students);
PrintStudentsinFile(students,"Students.bin");
string groupDelete;
cout << "Enter group where you want to delete students: ";
cin >> groupDelete;
DeleteformFIle(students, groupDelete, avarageGrades);

cout << "After delete " << endl;
printStudent(students);
PrintStudentsinFile(students,"Students.bin");
   
}