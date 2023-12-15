#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

struct Employee
{
    char name[100];
    char position[40];
    int birthYear;
    int salary;
};

void formEmployees(const char *file, int count);
void printEmployees(const char *file, int count);
void delBySurname(const char *file, int &count, string surname);
string getSurname(char* p);
void addEmployee(const char *file, int &count, int index);

int main()
{
    int count, index;
    string surname;

    cout << "How many employees? ";
    cin >> count;

    formEmployees("f.dat", count);

    cout << endl;
    printEmployees("f.dat", count);

    // Delete employee by surname
    cout << "Enter the surname of employee to delete: ";
    cin >> surname;

    delBySurname("f.dat", count, surname);

    cout << endl;
    printEmployees("f.dat", count);

    // Add employee after element
    cout << "Enter the number of employee to add after (number >= 1): ";
    cin >> index;

    addEmployee("f.dat", count, index);

    cout << endl;
    printEmployees("f.dat", count);

    return 0;
}
void formEmployees(const char *file, int count)
{
    FILE *f;
    
    // Open file
    if (!(f=fopen(file, "wb")))
    {
        cerr << "Failed to open file!\n" << endl;
        exit(1);
    }
    Employee p;

    for(int i = 0; i < count; i++)
    {
        cout << "Employee " << i + 1 << ":" << endl;
        cin.ignore();

        cout << "Name: "; cin.getline(p.name, sizeof(p.name));
        cout << "Position: "; cin.getline(p.position, sizeof(p.position));
        cout << "Year of birth: "; cin >> p.birthYear;
        cout << "Salary: "; cin >> p.salary;
        
        // Write to file
        fwrite(&p, sizeof(Employee),1,f);
        if (ferror(f))
        {
            cerr << "Failed to write to file!\n" << endl;
            exit(2);
        }
    }

    fclose(f);

    return;
}
void printEmployees(const char *file, int count)
{
    FILE *f;
    Employee p;

    // Read from file
    if (!(f=fopen(file, "rb")))
    {
        cerr << "Failed to open file!\n" << endl;
        exit(1);
    }

    for(int i = 0; !feof(f) && i < count; i++)
    {
        fread(&p, sizeof(Employee),1,f);
        cout << "Employee " << i + 1 << ":" << endl;
        cout << p.name << endl;
        cout << p.position << endl;
        cout << p.birthYear << endl;
        cout << p.salary << endl;
    }

    fclose(f);

    return;
}
void delBySurname(const char *file, int &count, string surname)
{
    FILE *f;
    FILE *t;
    Employee p;
    string s;
    
    // Read from file
    if (!(f=fopen(file, "rb")))
    {
        cerr << "Failed to open file!\n" << endl;
        exit(1);
    }

    // Open temp file
    if (!(t=fopen("temp.dat", "wb")))
    {
        cerr << "Failed to open file!\n" << endl;
        exit(1);
    }


    for(int i = 0; !feof(f) && i < count; i++)
    {
        fread(&p, sizeof(Employee),1,f);

        fwrite(&p, sizeof(Employee),1,t);
        if (ferror(t))
        {
            cerr << "Failed to write to file!\n" << endl;
            exit(2);
        }
    }

    fclose(f);
    fclose(t);

    // Read from temp file
    if (!(t=fopen("temp.dat", "rb")))
    {
        cerr << "Failed to open file!\n" << endl;
        exit(1);
    }

    // Open file
    if (!(f=fopen(file, "wb")))
    {
        cerr << "Failed to open file!\n" << endl;
        exit(1);
    }

    for(int i = 0; !feof(f) && i < count; i++)
    {
        fread(&p, sizeof(Employee),1,t);

        s = getSurname(p.name);

        if(s == surname)
        {
            count--;
            i--;
            continue;
        }

        fwrite(&p, sizeof(Employee),1,f);
        if (ferror(f))
        {
            cerr << "Failed to write to file!\n" << endl;
            exit(2);
        }
    }

    fclose(f);
    fclose(t);

    return;
}
string getSurname(char* p)
{
    string s = "";

    while(*p != ' ' && *p != '\0')
    {
        s += *p;
        p++;
    }

    return s;
}
void addEmployee(const char *file, int &count, int index)
{
    if(index < 1 || index > count)
    {
        return;
    }

    FILE *f;
    FILE *t;
    Employee p;
    
    // Read from file
    if (!(f=fopen(file, "rb")))
    {
        cerr << "Failed to open file!\n" << endl;
        exit(1);
    }

    // Open temp file
    if (!(t=fopen("temp.dat", "wb")))
    {
        cerr << "Failed to open file!\n" << endl;
        exit(1);
    }


    for(int i = 0; !feof(f) && i < count; i++)
    {
        fread(&p, sizeof(Employee),1,f);

        fwrite(&p, sizeof(Employee),1,t);
        if (ferror(t))
        {
            cerr << "Failed to write to file!\n" << endl;
            exit(2);
        }
    }

    fclose(f);
    fclose(t);

    // Read from temp file
    if (!(t=fopen("temp.dat", "rb")))
    {
        cerr << "Failed to open file!\n" << endl;
        exit(1);
    }

    // Open file
    if (!(f=fopen(file, "wb")))
    {
        cerr << "Failed to open file!\n" << endl;
        exit(1);
    }

    for(int i = 0; !feof(f) && i < count; i++)
    {

        if(i == index)
        {
            cout << "Employee " << i + 1 << ":" << endl;
            cin.ignore();

            cout << "Name: "; cin.getline(p.name, sizeof(p.name));
            cout << "Position: "; cin.getline(p.position, sizeof(p.position));
            cout << "Year of birth: "; cin >> p.birthYear;
            cout << "Salary: "; cin >> p.salary;
            
            fwrite(&p, sizeof(Employee),1,f);
            if (ferror(f))
            {
                cerr << "Failed to write to file!\n" << endl;
                exit(2);
            }
        }

        fread(&p, sizeof(Employee),1,t);
        fwrite(&p, sizeof(Employee),1,f);
        if (ferror(f))
        {
            cerr << "Failed to write to file!\n" << endl;
            exit(2);
        }
    }

    if(count == index)
        {
            cout << "Employee " << index + 1 << ":" << endl;
            cin.ignore();

            cout << "Name: "; cin.getline(p.name, sizeof(p.name));
            cout << "Position: "; cin.getline(p.position, sizeof(p.position));
            cout << "Year of birth: "; cin >> p.birthYear;
            cout << "Salary: "; cin >> p.salary;
            
            fwrite(&p, sizeof(Employee),1,f);
            if (ferror(f))
            {
                cerr << "Failed to write to file!\n" << endl;
                exit(2);
            }
        }


    count++;

    fclose(f);
    fclose(t);

    return;
}
