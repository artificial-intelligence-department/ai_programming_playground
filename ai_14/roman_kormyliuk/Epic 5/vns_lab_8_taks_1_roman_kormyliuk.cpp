#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура "Інформація"
struct Information {
    string nosiy;
    double volume;
    string name;
    string author;
};

// Функція для друку інформації
void printInformation(const Information& info) {
    cout << "Носій: " << info.nosiy << endl;
    cout << "Об'єм: " << info.volume << endl;
    cout << "Назва: " << info.name << endl;
    cout << "Автор: " << info.author << endl;
    cout << "---------------------------" << endl;
}

// Функція для знищення елемента з заданим об'ємом
void deleteElementByVolume(const string& filename, double targetVolume) {
    ifstream inputFile(filename, ios::binary);
    ofstream tempFile("temp.bin", ios::binary);

    if (!inputFile.is_open() || !tempFile.is_open()) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }

    Information info;

    bool elementDeleted = false;

    while (inputFile.read(reinterpret_cast<char*>(&info), sizeof(Information))) {
        if (info.volume == targetVolume && !elementDeleted) {
            elementDeleted = true;
            continue; // пропустити перший елемент з заданим об'ємом
        }

        tempFile.write(reinterpret_cast<const char*>(&info), sizeof(Information));
    }

    inputFile.close();
    tempFile.close();

    remove(filename.c_str());
    rename("temp.bin", filename.c_str());

    if (!elementDeleted) {
        cerr << "Елемент з об'ємом " << targetVolume << " не знайдено!" << endl;
    } else {
        cout << "Елемент з об'ємом " << targetVolume << " був успішно видалений." << endl;
    }
}

// Функція для додавання елемента перед елементом з заданим номером
void addElementBeforeIndex(const string& filename, int targetIndex, const Information& newInfo) {
    ifstream inputFile(filename, ios::binary);
    ofstream tempFile("temp.bin", ios::binary);

    if (!inputFile.is_open() || !tempFile.is_open()) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }

    Information info;
    int currentIndex = 0;
    bool elementAdded = false;

    while (inputFile.read(reinterpret_cast<char*>(&info), sizeof(Information))) {
        if (currentIndex == targetIndex && !elementAdded) {
            tempFile.write(reinterpret_cast<const char*>(&newInfo), sizeof(Information));
            elementAdded = true;
        }

        tempFile.write(reinterpret_cast<const char*>(&info), sizeof(Information));

        currentIndex++;
    }

    inputFile.close();
    tempFile.close();

    remove(filename.c_str());
    rename("temp.bin", filename.c_str());

    if (!elementAdded) {
        cerr << "Елемент не був доданий. Невірний номер індексу." << endl;
    } else {
        cout << "Елемент був успішно доданий перед індексом " << targetIndex << "." << endl;
    }
}

int main() {
    // Приклад використання
    const string filename = "information.bin";

    // Створення файлу із даними
    ofstream outputFile(filename, ios::binary);
    Information info1 = { "DVD", 4.7, "Movie1", "Director1" };
    Information info2 = { "CD", 0.7, "Music1", "Artist1" };
    Information info3 = { "USB", 32.0, "Data1", "Owner1" };

    outputFile.write(reinterpret_cast<const char*>(&info1), sizeof(Information));
    outputFile.write(reinterpret_cast<const char*>(&info2), sizeof(Information));
    outputFile.write(reinterpret_cast<const char*>(&info3), sizeof(Information));

    outputFile.close();

    // Друк початкового стану файлу
    ifstream inputFile(filename, ios::binary);
    Information currentInfo;

    cout << "Початковий стан файлу:" << endl;
    while (inputFile.read(reinterpret_cast<char*>(&currentInfo), sizeof(Information))) {
        printInformation(currentInfo);
    }
    cout << endl;

    inputFile.close();

    // Знищення елемента з об'ємом 0.7І
    deleteElementByVolume(filename, 0.7);

    // Додавання нового елемента перед індексом 1
    Information newInfo = { "Blu-ray", 25.0, "Movie2", "Director2" };
    addElementBeforeIndex(filename, 1, newInfo);

    // Друк оновленого стану файлу
    inputFile.open(filename, ios::binary);
    cout << "Оновлений стан файлу:" << endl;
    while (inputFile.read(reinterpret_cast<char*>(&currentInfo), sizeof(Information))) {
        printInformation(currentInfo);
    }

    inputFile.close();

    return 0;
}