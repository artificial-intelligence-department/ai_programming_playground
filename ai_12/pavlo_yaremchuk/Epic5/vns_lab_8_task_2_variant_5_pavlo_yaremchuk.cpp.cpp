#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Person
{
    char surname[20];
    char name[20];
    char fathername[20];
    int birthYear;
    int height;
    int weight;
};

void addtoFile(const char* filename, vector<Person>& people)
{
    ofstream fileP(filename, ios::binary);
    if (!fileP.is_open())
    {
        cout << "Помилка запису в файл" << endl;
        return;
    }

    for (int i = 0; i < people.size(); ++i)
    {
        fileP.write(reinterpret_cast<const char*>(&people[i]), sizeof(Person));
    }
    fileP.close();
}

void readFile(int countPeople, vector<Person>& person)
{
    for (int i = 0; i < countPeople; ++i)
    {
        cout << person[i].surname << "\t\t";
    }
    cout << endl;

    for (int i = 0; i < countPeople; ++i)
    {
        cout << person[i].name << "\t\t";
    }
    cout << endl;

    for (int i = 0; i < countPeople; ++i)
    {
        cout << person[i].fathername << "\t\t";
    }
    cout << endl;

    for (int i = 0; i < countPeople; ++i)
    {
        cout << person[i].birthYear << "\t\t";
    }
    cout << endl;

    for (int i = 0; i < countPeople; ++i)
    {
        cout << person[i].height << "\t\t";
    }
    cout << endl;

    for (int i = 0; i < countPeople; ++i)
    {
        cout << person[i].weight << "\t\t";
    }
    cout << endl;
}

void DeletebyHW(int& countPeople, vector<Person>& person, int banedH, int banedW, const char* filename)
{
    person.erase(remove_if(person.begin(), person.end(),
                           [banedW, banedH](const Person& person) 
                           {
                               return person.weight == banedW && person.height == banedH;
                           }),
                 person.end());
    --countPeople;
    addtoFile(filename, person);
}

void PersonToAddF(Person& PersonToAdd)
{
    cin >> PersonToAdd.surname;
    cin >> PersonToAdd.name;
    cin >> PersonToAdd.fathername;
    cin >> PersonToAdd.birthYear;
    cin >> PersonToAdd.height;
    cin >> PersonToAdd.weight;
}

void AddAfterSurname(vector<Person>& person, const char* surnameToAddAfter, int& countPeople, const char* filename)
{
    for (int i = 0; i < countPeople; ++i)
    {
        Person person2 = person[i];
        if (strcmp(person2.surname, surnameToAddAfter) == 0)
        {
            Person PersonToAdd;
            PersonToAddF(PersonToAdd);
            auto position = person.begin() + (i + 1);
            person.insert(position, PersonToAdd);
            ++countPeople;
            addtoFile(filename, person);
        }
    }
}

void AddPerson(vector<Person>& person, int countPeople)
{
    for (int i = 0; i < countPeople; ++i)
    {
        cout << "Прізвище: ";
        cin >> person[i].surname;

        cout << "Ім'я: ";
        cin >> person[i].name;

        cout << "По батькові: ";
        cin >> person[i].fathername;

        cout << "Рік народження: ";
        cin >> person[i].birthYear;

        cout << "Ріст: ";
        cin >> person[i].height;

        cout << "Bara: ";
        cin >> person[i].weight;
    }
}

int main()
{
    char filename[20];
    cout << "Введіть назву файлу: ";
    cin >> filename;
    int countPeople;
    cout << "Введіть кількість людей: ";
    cin >> countPeople;
    int banedH, banedW;
    cout << "Введіть зріст та вагу для видалення: ";
    cin >> banedH >> banedW;
    vector<Person> person(countPeople);
    addtoFile(filename, person);
    AddPerson(person, countPeople);
    addtoFile(filename, person);
    readFile(countPeople, person);
    DeletebyHW(countPeople, person, banedH, banedW, filename);
    cout << "Після видалення:" << endl;
    readFile(countPeople, person);
    char surnameToAddAfter[20];
    cout << "Введіть прізвище людини, після якої треба вставити нову: ";
    cin >> surnameToAddAfter;
    AddAfterSurname(person, surnameToAddAfter, countPeople, filename);
    cout << endl;
    readFile(countPeople, person);

    return 0;
}