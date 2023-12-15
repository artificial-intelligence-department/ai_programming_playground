#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

const int MAX_PEOPLE = 100;

struct Person {
    string lastName;
    string firstName;
    string middleName;
    string address;
    string phoneNumber;
    int age;
};

void printPerson(const Person& p) {
    cout << "Last Name: " << p.lastName << endl;
    cout << "First Name: " << p.firstName << endl;
    cout << "Middle Name: " << p.middleName << endl;
    cout << "Address: " << p.address << endl;
    cout << "Phone Number: " << p.phoneNumber << endl;
    cout << "Age: " << p.age << endl;
    cout << "---------------------" << endl;
}

void writeToFile(const Person people[], int size, const string& fileName) {
    ofstream file(fileName, ios::binary);
    if (!file.is_open()) {
        cout << "Error opening the file." << endl;
        return;
    }
    file.write(reinterpret_cast<const char*>(people), size * sizeof(Person));
    file.close();
}

void readFromFile(Person people[], int& size, const string& fileName) {
    ifstream file(fileName, ios::binary);
    if (!file.is_open()) {
        cout << "Error opening the file." << endl;
        return;
    }
    size = 0;
    while (file.read(reinterpret_cast<char*>(&people[size]), sizeof(Person))) {
        size++;
    }
    file.close();
}

void deleteByAge(Person people[], int& size, int ageToDelete) {
    int newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (people[i].age != ageToDelete) {
            people[newSize++] = people[i];
        }
    }
    size = newSize;
}

void addNumber(Person people[], int& size, string numberToSearch, const Person& newPerson) {
    for (int i = 0; i < size; ++i) {
        if (people[i].phoneNumber == numberToSearch) {
            for (int j = size; j > i + 1; --j) {
                people[j] = people[j - 1];
            }
            people[i + 1] = newPerson;
            size++;
            return;
        }
    }

    cout << "Person with number " << numberToSearch << " not found." << endl;
}

int main() {
    Person people[MAX_PEOPLE];
    int size = 0;
    people[size++] = {"Zimnov", "Oleksandr", "Serhiyovych", "Shevchenko 12", "0631761061", 19};
    people[size++] = {"Silver", "Vladyslav", "Bohdanovich", "Shukhevicha 17", "0662356956", 25};
    people[size++] = {"Deruk", "Sergey", "Andreyovych", "Mazepy 21", "0996363524", 35};
    writeToFile(people, size, "people.dat");
    readFromFile(people, size, "people.dat");
    for (int i = 0; i < size; ++i) {
        printPerson(people[i]);
    }
    int ageToDelete = 35;
    deleteByAge(people, size, ageToDelete);
    cout << "After deleting people with age " << ageToDelete << ":" << endl;
    for (int i = 0; i < size; ++i) {
        printPerson(people[i]);
    }
    string numberToSearch = "0631761061";
    Person newPerson = {"New", "Oleg", "Nazariiovych", "Zolota 34", "0935561232", 40};
    addNumber(people, size, numberToSearch, newPerson);
    cout << "After adding a new person after number " << numberToSearch << ":" << endl;
    for (int i = 0; i < size; ++i) {
        printPerson(people[i]);
    }

    return 0;
}
