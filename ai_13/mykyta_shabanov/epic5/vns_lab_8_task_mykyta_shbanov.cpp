#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Scoolar {
  string lastName, name, surname,
    form, telNum;

  string 
  //оцінки з
    math,
    physic,
    ukrLang,
    literature;
};

void createFile()
{
    ofstream fout("scoolerInfo.dat", ios::binary);

    if (fout.is_open()) {
        fout.close();
        cout << "file was created>" << endl;
    } else
        cout << "err of creating file>" << endl;

    cout << endl;
}

    //зчитування записаних данних про студентів
Scoolar readfile(int index)
{
    ifstream fin("scoolerInfo.dat");

    for (int i = 0; i < index * 9; ++i)
    {
        string line;
        getline(fin, line);
    }
    
    Scoolar output;

    for(int j = 0; j < 9; j++)
    { //дазнаємось про конкретного студента
        string line;
        getline(fin, line);

        switch (j)
        {
        case 0:
            output.lastName = line;
            break;
        case 1:
            output.name = line;
            break;
        case 2:
            output.surname = line;
            break;
        case 3:
            output.form = line;
            break;
        case 4:
            output.telNum = line;
            break;
        case 5:
            output.math = line;
            break;
        case 6:
            output.physic = line;
            break;
        case 7:
            output.ukrLang = line;
            break;
        case 8:
            output.literature = line;
            break;
        
        default:
            break;
        }
    }
    return output;
}

void writeToFile(Scoolar scoolar, int studentsCount)
{
    /* ifstream fin("scoolerInfo.dat", ios::binary);

    if(fin.is_open())
    {
            //пропускаємо вже існуючих студентів, записуючи нового в кінець
        for(int i = 0; i < studentsCount * 9; ++i)
        {
            string line;
            getline(fin, line);
        }
    } */

    ofstream fout("scoolerInfo.dat", ios::binary | ios::app);
    
    if (fout.is_open()) 
    {
        fout << scoolar.lastName << endl;
        fout << scoolar.name << endl;
        fout << scoolar.surname << endl;
        fout << scoolar.form << endl;
        fout << scoolar.telNum << endl;
        fout << scoolar.math << endl;
        fout << scoolar.physic << endl;
        fout << scoolar.ukrLang << endl;
        fout << scoolar.literature << endl;
        cout << "Student information saved in file!" << endl;
    } else 
        cout << "Error writing to file!" << endl;

  fout.close();
}

Scoolar addNewScooler(int studentsCount)
{
    Scoolar input;
    // string whatToWrite[] = {"Last name> ", "Name> ", "Surname> "};
    cout << "Last name> "; cin >> input.lastName;
    cout << "Name> "; cin >> input.name;
    cout << "Surname> "; cin >> input.surname;

    cout << "Form> "; cin >> input.form;
    cout << "Tel. number> "; cin >> input.telNum;

    cout << "math grades> "; cin >> input.math;
    cout << "physic grades> "; cin >> input.physic;
    cout << "ukr lang grades> "; cin >> input.ukrLang;
    cout << "literature grades> "; cin >> input.literature;

    
    cout << "student created!> ";

    // students.push_back(input);
    writeToFile(input, studentsCount);
    return input;
}

void ShowInfoAbout(int student, vector<Scoolar> allStudents)
{
    Scoolar sclr = allStudents[student - 1];
    cout << "#<INFO>#" << endl;
    cout << "Student: " << sclr.lastName << " " << sclr.name << " " << sclr.surname << endl;
    cout << "Study in: " << sclr.form << "th grade" << endl;
    cout << "Tel. number: " << sclr.telNum << endl;
    cout << "subject grades:" << endl
        << "   Math: " << sclr.math << endl
        << "   Physic: " << sclr.physic << endl
        << "   Ukr. lang: " << sclr.ukrLang << endl
        << "   Literature: " << sclr.literature << endl;
    cout << "-----------------" << endl
        << "To show info about student - put serial number, to exit - put 0> ";
}

void ShowAllStudents(vector<Scoolar> allStudents, int length)
{
    cout << "#<STUDENTS>#" << endl;
    for(int i = 0; i < length; i++)
    {
        cout << i+1 << ") " << allStudents[i].lastName << endl;
    }
    cout << "^^^^^^^^^^^^^^" << endl;

    cout << "To see more information about a student, write his serial number; to exit enter 0" << endl << "> ";
    
    int point;
    while (true)
    {
        cin >> point;

        if(point > length)
            cout << "incorect student serial number; Try aganin> ";
        else if(point > 0)
            ShowInfoAbout(point, allStudents);
        else break;
    }
}

int howManyStudents()
{
    ifstream fin("scoolerInfo.dat", ios::binary);

    int totalLines = 0;
    string line;
    while(getline(fin, line))
        totalLines++;

    return totalLines / 9;
}

void deleteStudent(vector<Scoolar>& students, int index) {
    if (index < 0 || index >= students.size()) {
        cerr << "Invalid index>" << endl;
        return;
    }

    ifstream fin("scoolerInfo.dat");
    ofstream fout("temp.dat");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error opening files." << endl;
        return;
    }

    string line;
    int curLine = 0;

    while (getline(fin, line)) {
        curLine++;

        if (curLine >= (index-1) * 9 && curLine <= index * 9)
            continue;

        fout << line << endl;
    }

    fin.close();
    fout.close();

    remove("scoolerInfo.dat");
    rename("temp.dat", "scoolerInfo.dat");

    cout << "Student deleted successfully." << endl;
}

int main()
{
    int studentsCount = howManyStudents();
    vector<Scoolar> students;

        //якщо ми ще не додавали студентів в базу, то створюємо новий файл
    if(studentsCount == 0)
        createFile();
    else
    {
        //а якщо додавали, то считуємо всю відому інформацію та записуємо її
        for (int i = 0; i < studentsCount; i++)
            students.push_back(readfile(i));
    }

        //це менюшка
    while (true)
    {
        int point;
        cout << " #<MENU># " << endl
            << "0. Out" << endl
            << "1. Add new scooler" << endl
            << "2. See all students" << endl
            << "3. Delete studenet" << endl
                <<endl;
        
        cin >> point;

        switch (point)
        {
        case 0:
            return 0;
            break;
        case 1:
            students.push_back(addNewScooler(studentsCount));
            studentsCount++;
            break;
        case 2:
            ShowAllStudents(students, studentsCount);
            break;
        case 3:
            cout << "enter index> ";
            int point;
            cin >> point;

            if(point > studentsCount)
                cout << "Error serial num>" << endl;
            else if(point > 0)
            {
                students.erase(students.begin() + point-1);
                deleteStudent(students, point);
                studentsCount--;
            }
            break;

        default:
            break;
        }
    }
    return 0;
}
