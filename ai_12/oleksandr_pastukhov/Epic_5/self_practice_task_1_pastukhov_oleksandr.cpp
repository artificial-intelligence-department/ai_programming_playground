#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Person {
    string name;
    int age;
};

void writeToTextFile(const string& filename, const Person& person) {
    ofstream file(filename);

    if (file.is_open()) {
        file << person.name << " " << person.age;
        file.close();
        cout << "Дані успішно записано у файл." << endl;
    } else {
        cout << "Помилка відкриття файлу для запису." << endl;
    }
}

void readFromTextFile(const string& filename) {
    ifstream file(filename);

    if (file.is_open()) {
        Person person;
        file >> person.name >> person.age;

        cout << "Ім'я: " << person.name << endl <<"Вік: " << person.age << endl;
        file.close();
    } else {
        cout << "Помилка відкриття файлу для читання." << endl;
    }
}

int main() {
    Person person;

    cout << "Введіть ваше ім'я: ";
    getline(cin, person.name);

    cout << "Введіть ваш вік: ";
    cin >> person.age;

    writeToTextFile("person_data.txt", person);

    cout << endl << "Дані, зчитані з файлу:" << endl;
    readFromTextFile("person_data.txt");

    return 0;
}
