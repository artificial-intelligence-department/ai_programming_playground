#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Person
{
    char name[100];
    char address[100];
    char mobile[20];
    int age;
};

void write_to_file(const char* filename, int &n);
void read_from_file(const char* filename, int &n);
void delete_person(const char* filename, int age);
void add_person(const char* filename, int index);

int main()
{
    int n;
    cout << "How much structures you want to enter?";
    cin >> n;

    cin.ignore();

    write_to_file("file.txt", n);
    read_from_file("file.txt", n);
    add_person("file.txt", 1);
    delete_person("file.txt", 16);
    read_from_file("file.txt", n);

    return 0;
}

void write_to_file(const char* filename, int &n)
{
    Person person[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter name: ";
        cin.getline(person[i].name, 100);

        cout << "Enter address: ";
        cin.getline(person[i].address, 100);

        cout << "Enter mobile: ";
        cin.getline(person[i].mobile, 20);

        cout << "Enter age: ";
        cin >> person[i].age;

        cin.ignore();  // Ignore the newline character left in the buffer
    }

    ofstream file1(filename, ios::out | ios::binary);

    if (!file1.is_open())
    {
        cout << "Failure" << endl;
    }

    for (int i = 0; i < n; i++)
    {
        file1.write((char*)&person[i], sizeof(Person));
    }

    file1.close();
}

void read_from_file(const char* filename, int &n)
{
    Person person[n];

    ifstream file2(filename, ios::in | ios::binary);

    if (!file2.is_open())
    {
        cout << "Failure" << endl;
    }

    for (int i = 0; i < n; i++)
    {
        file2.read((char*)&person[i], sizeof(Person));
    }

    for (int i = 0; i < n; i++)
    {
        cout << person[i].name << endl;
        cout << person[i].address << endl;
        cout << person[i].mobile << endl;
        cout << person[i].age << endl;
    }

    file2.close();
}

void delete_person(const char* filename, int age)
{
    Person person;

    ifstream file1(filename, ios::in | ios::binary);
    ofstream file2("temporary.txt", ios::out | ios::binary);

    if (!file1.is_open() || !file2.is_open())
    {
        cout << "Failure" << endl;
        return;
    }

    while (file1.read((char*)&person, sizeof(Person)))
    {
        if (person.age != age)
        {
            file2.write((char*)&person, sizeof(Person));
        }
    }

    file1.close();
    file2.close();

    remove(filename);
    rename("temporary.txt", filename);
}

void add_person(const char* filename, int index)
{
    Person new_person;

    cout << "Enter name: ";
    cin.getline(new_person.name, 100);

    cout << "Enter address: ";
    cin.getline(new_person.address, 100);

    cout << "Enter mobile: ";
    cin.getline(new_person.mobile, 20);

    cout << "Enter age: ";
    cin >> new_person.age;

    cin.ignore();  // Ignore the newline character left in the buffer

    Person person;
    ifstream file1(filename, ios::in | ios::binary);
    ofstream file2("temporary.txt", ios::out | ios::binary);

    if (!file1.is_open() || !file2.is_open())
    {
        cout << "Failure" << endl;
        return;
    }

    int current_index = 0;
    while (file1.read((char*)&person, sizeof(Person)))
    {
        file2.write((char*)&person, sizeof(Person));

        if (current_index == index)
        {
            file2.write((char*)&new_person, sizeof(Person));
        }

        current_index++;
    }

    file1.close();
    file2.close();

    remove(filename);
    rename("temporary.txt", filename);
}