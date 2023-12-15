#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Person {
    char surname[50];
    char name[50];
    char patronymic[50];
    int birthYear;
    double height;
    double weight;
};

void printBinaryFileContents(const char* filename) {
    ifstream inFile(filename, ios::binary);

    if (!inFile.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }

    Person person;
    while (inFile.read(reinterpret_cast<char*>(&person), sizeof(person))) {
        cout << "Surname: " << person.surname << "\n";
        cout << "Name: " << person.name << "\n";
        cout << "Patronymic: " << person.patronymic << "\n";
        cout << "Birth Year: " << person.birthYear << "\n";
        cout << "Height: " << person.height << "\n";
        cout << "Weight: " << person.weight << "\n\n";
    }

    inFile.close();
}

void deleteByHeightAndWeight(const char* filename, double heightToDelete, double weightToDelete) {
    ifstream inFile(filename, ios::binary);
    ofstream outFile("temp.bin", ios::binary);

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Unable to open file for deletion." << endl;
        return;
    }

    Person person;
    while (inFile.read(reinterpret_cast<char*>(&person), sizeof(person))) {
        if (person.height != heightToDelete || person.weight != weightToDelete) {
            outFile.write(reinterpret_cast<char*>(&person), sizeof(person));
        }
    }

    inFile.close();
    outFile.close();

    remove(filename);
    rename("temp.bin", filename);
}

void addAfterSurname(const char* filename, const char* surnameToFind, const Person& newPerson) {
    ifstream inFile(filename, ios::binary);
    ofstream outFile("temp.bin", ios::binary);

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Unable to open file for addition." << endl;
        return;
    }

    Person person;
    bool surnameFound = false;

    while (inFile.read(reinterpret_cast<char*>(&person), sizeof(person))) {
        outFile.write(reinterpret_cast<char*>(&person), sizeof(person));

        if (strcmp(person.surname, surnameToFind) == 0) {
            outFile.write(reinterpret_cast<const char*>(&newPerson), sizeof(newPerson));
            surnameFound = true;
        }
    }

    inFile.close();
    outFile.close();

    remove(filename);
    rename("temp.bin", filename);

    if (!surnameFound) {
        cerr << "Surname not found. New person's data was not added." << endl;
    }
}

int main() {
    ofstream createFile("people_data.bin", ios::binary);

    if (!createFile.is_open()) {
        cerr << "Unable to create file." << endl;
        return 1;
    }

    Person person1;
    cout << "Enter surname: ";
    cin >> person1.surname;

    cout << "Enter name: ";
    cin >> person1.name;

    cout << "Enter patronymic: ";
    cin >> person1.patronymic;

    cout << "Enter birth year: ";
    cin >> person1.birthYear;

    cout << "Enter height: ";
    cin >> person1.height;

    cout << "Enter weight: ";
    cin >> person1.weight;

    createFile.write(reinterpret_cast<const char*>(&person1), sizeof(person1));

    createFile.close();

    cout << "Initial contents of binary file:\n";
    printBinaryFileContents("people_data.bin");

    deleteByHeightAndWeight("people_data.bin", 175.5, 80.0);
    cout << "\nContents after deletion:\n";
    printBinaryFileContents("people_data.bin");

    Person newPerson;
    cout << "Enter new person details:\n";
    cout << "Enter surname to find: ";
    cin >> newPerson.surname;

    cout << "Enter name: ";
    cin >> newPerson.name;

    cout << "Enter patronymic: ";
    cin >> newPerson.patronymic;

    cout << "Enter birth year: ";
    cin >> newPerson.birthYear;

    cout << "Enter height: ";
    cin >> newPerson.height;

    cout << "Enter weight: ";
    cin >> newPerson.weight;

    addAfterSurname("people_data.bin", "Johnson", newPerson);
    cout << "\nContents after addition:\n";
    printBinaryFileContents("people_data.bin");

    return 0;
}
