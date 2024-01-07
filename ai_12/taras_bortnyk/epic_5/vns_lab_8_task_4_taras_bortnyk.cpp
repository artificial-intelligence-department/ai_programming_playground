#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Person {
    char fullName[100];
    char address[100];
    char phoneNumber[20];
    int age;
};

void formPersons(const char *file, int count);
void printPersons(const char *file, int count);
void deleteByAge(const char *file, int &count, int ageToDelete);
void addPerson(const char *file, int &count, int index);

int main() {
    int count, index, age;

    cout << "How many people? ";
    cin >> count;

    formPersons("people.dat", count);

    cout << endl;
    printPersons("people.dat", count);

    cout << "Enter age of people to delete: ";
    cin >> age;

    deleteByAge("people.dat", count, age);

    cout << endl;
    printPersons("people.dat", count);

    cout << "Enter the number of person to add after (number >= 1): ";
    cin >> index;

    addPerson("people.dat", count, index);

    cout << endl;
    printPersons("people.dat", count);

    return 0;
}

void formPersons(const char *file, int count) {
    ofstream outFile(file, ios::binary);

    if (!outFile) {
        cerr << "Failed to open file!" << endl;
        exit(1);
    }

    Person p;

    for (int i = 0; i < count; ++i) {
        cout << "Person " << i + 1 << ":" << endl;
        cin.ignore();

        cout << "Full Name: "; cin.getline(p.fullName, sizeof(p.fullName));
        cout << "Address: "; cin.getline(p.address, sizeof(p.address));
        cout << "Phone Number: "; cin.getline(p.phoneNumber, sizeof(p.phoneNumber));
        cout << "Age: "; cin >> p.age;

        outFile.write(reinterpret_cast<char*>(&p), sizeof(Person));
        if (!outFile) {
            cerr << "Failed to write to file!" << endl;
            exit(2);
        }
    }
}

void printPersons(const char *file, int count) {
    ifstream inFile(file, ios::binary);

    if (!inFile) {
        cerr << "Failed to open file!" << endl;
        exit(1);
    }

    Person p;

    for (int i = 0; i < count && inFile.read(reinterpret_cast<char*>(&p), sizeof(Person)); ++i) {
        cout << "Person " << i + 1 << ":" << endl;
        cout << "Full Name: " << p.fullName << endl;
        cout << "Address: " << p.address << endl;
        cout << "Phone Number: " << p.phoneNumber << endl;
        cout << "Age: " << p.age << endl;
    }

    inFile.close();
}

void deleteByAge(const char *file, int &count, int ageToDelete) {
    ifstream inFile(file, ios::binary);
    ofstream tempFile("temp.dat", ios::binary);

    if (!inFile || !tempFile) {
        cerr << "Failed to open files!" << endl;
        exit(1);
    }

    Person p;

    while (inFile.read(reinterpret_cast<char*>(&p), sizeof(Person))) {
        if (p.age != ageToDelete) {
            tempFile.write(reinterpret_cast<char*>(&p), sizeof(Person));
            if (!tempFile) {
                cerr << "Failed to write to file!" << endl;
                exit(2);
            }
        } else {
            count--;
        }
    }

    inFile.close();
    tempFile.close();

    remove(file);
    rename("temp.dat", file);
}

void addPerson(const char *file, int &count, int index) {
    if (index < 1 || index > count + 1) {
        return;
    }

    ifstream inFile(file, ios::binary);
    ofstream tempFile("temp.dat", ios::binary);

    if (!inFile || !tempFile) {
        cerr << "Failed to open files!" << endl;
        exit(1);
    }

    Person p;

    for (int i = 0; i < count; ++i) {
        inFile.read(reinterpret_cast<char*>(&p), sizeof(Person));
        tempFile.write(reinterpret_cast<char*>(&p), sizeof(Person));

        if (i == index - 1) {
            cout << "Enter details for new person:" << endl;
            cin.ignore();

            cout << "Full Name: "; cin.getline(p.fullName, sizeof(p.fullName));
            cout << "Address: "; cin.getline(p.address, sizeof(p.address));
            cout << "Phone Number: "; cin.getline(p.phoneNumber, sizeof(p.phoneNumber));
            cout << "Age: "; cin >> p.age;

            tempFile.write(reinterpret_cast<char*>(&p), sizeof(Person));
        }
    }

    inFile.close();
    tempFile.close();

    remove(file);
    rename("temp.dat", file);

    count++;
}
