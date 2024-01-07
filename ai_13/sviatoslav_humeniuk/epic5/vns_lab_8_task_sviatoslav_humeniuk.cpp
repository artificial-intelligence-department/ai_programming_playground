#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Person { // Створюється вектор структур 
    string surname;
    string name;
    string patronymic;
    string address;
    string phoneNumber;
    int age;
};

void printPerson(const Person& person) {
    cout << "surname: " << person.surname << endl;
    cout << "name: " << person.name << endl;
    cout << "patromymic: " << person.patronymic << endl;
    cout << "home adress: " << person.address << endl;
    cout << "phone number: " << person.phoneNumber << endl;
    cout << "age: " << person.age << endl << endl;
}

void wrbinaryfile(const string& filename, const vector<Person>& people) { // Програма записує цей вектор у бінарний файл
    ofstream file(filename, ios::binary); // Створення бінарного файлу
    if (!file) {
        cerr << "invalid" << endl;
        return;
    }

    for (const Person& person : people) {
        file.write(reinterpret_cast<const char*>(&person), sizeof(Person)); 
    }

    file.close();
}

void rdbinaryfile(const string& filename) {
    ifstream file(filename, ios::binary); // Створює об*єкт для читання бінарного файлу
    if (!file) {
        cerr << "invalid." << endl;
        return;
    }

    Person person;
    while (file.read(reinterpret_cast<char*>(&person), sizeof(Person))) {
        printPerson(person);
    }

    file.close();
}

void rembyag(const string& filename, int targetAge) { // Функція видаляє людей з певним віком
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "invalid." << endl;
        return;
    }

    vector<Person> people;
    Person person;

    while (inFile.read(reinterpret_cast<char*>(&person), sizeof(Person))) {
        if (person.age != targetAge) {
            people.push_back(person);
        }
    }

    inFile.close();

    wrbinaryfile(filename, people);
}

void addaftnumb(const string& filename, int targetNumber, const Person& newPerson) { // Функція додає людину після іншої людини з певним віком
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "invalid." << endl;
        return;
    }

    vector<Person> people;
    Person person;

    while (inFile.read(reinterpret_cast<char*>(&person), sizeof(Person))) {
        people.push_back(person);

        if (person.age == targetNumber) {
            people.push_back(newPerson);
        }
    }

    inFile.close();

    wrbinaryfile(filename, people);
}

int main() {
    vector<Person> people = {
        {"Ivanov", "Ivan", "Ivanovich", "Kyiv", "380958218307", 25},
        {"Petrov", "Petro", "Petrovich", "Lviv", "380633809056", 40},
        {"Sidorov", "Sidor", "Sidorovich", "Odessa", "380674296979", 25}
    };

    wrbinaryfile("people.dat", people);

    cout << "before changes:" << endl << endl;
    rdbinaryfile("people.dat");

    rembyag("people.dat", 25);    // Знищити усі елементи із заданим віком (наприклад, 25)

    Person newPerson = {"Panasenko", "Panas", "Panasovich", "Chernihiv", "380694201337", 35};    // Додати елемент після елемента із заданим номером (наприклад, 40)

    addaftnumb("people.dat", 40, newPerson);

    cout << "after changes:" << endl << endl;
    rdbinaryfile("people.dat");

    return 0;
}