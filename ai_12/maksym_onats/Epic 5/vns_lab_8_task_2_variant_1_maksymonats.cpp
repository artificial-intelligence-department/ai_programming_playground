#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Структура "Музичний диск"
struct MusicDisc {
    string title;
    string author;
    int duration;
    float price;
};

// Функція для видалення елемента з файлу
void deleteDisc(const string& filename, int index) {
    fstream file(filename, ios::binary | ios::in | ios::out);
    if (!file) {
        cerr << "An error occurred while opening the file." << endl;
        return;
    }

    // Обчислення розміру структури
    int size = sizeof(MusicDisc);

    // Встановлення позиції для видалення елемента
    file.seekp(index * size, ios::beg);

    // Запис нульових байтів для елемента, щоб він був видалений
    char* buffer = new char[size];
    memset(buffer, 0, size);
    file.write(buffer, size);

    delete[] buffer;
    file.close();

    cout << "An element with an index " << index << " was deleted." << endl;
}

// Функція для додавання нового елемента до файлу
void addDisc(const string& filename, const MusicDisc& disc) {
    fstream file(filename, ios::binary | ios::in | ios::out | ios::app);
    if (!file) {
        cerr << "An error occurred while opening the file." << endl;
        return;
    }

    // Запис нового елемента в кінець файлу
    file.write(reinterpret_cast<const char*>(&disc), sizeof(MusicDisc));

    file.close();

    cout << "A new item has been added to the file." << endl;
}

// Функція для друку вмісту файлу
void printFileContent(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "An error occurred while opening the file." << endl;
        return;
    }

    // Переміщаємося до початку файлу
    file.seekg(0, ios::beg);

    // Отримуємо розмір структури
    int size = sizeof(MusicDisc);

    MusicDisc disc;
    int index = 0;

    // Читаємо кожен елемент з файлу та виводимо його
    while (file.read(reinterpret_cast<char*>(&disc), size)) {
        cout << "Element " << index << ":" << endl;
        cout << "Name: " << disc.title << endl;
        cout << "Author: " << disc.author << endl;
        cout << "Duration: " << disc.duration << " Sec" << endl;
        cout << "Price: " << disc.price << " UAH" << endl;
        cout << endl;

        index++;
    }

    file.close();
}

int main() {
    string filename = "music.bin";

    // Створення двійкового файлу з елементами структури "Музичний диск"
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "An error occurred while opening the file" << endl;
        return 1;
    }

    MusicDisc disc1 = { "Title 1", "Author 1", 180, 9.99 };
    MusicDisc disc2 = { "Title 2", "Author 2", 210, 12.99 };
    MusicDisc disc3 = { "Title 3", "Author 3", 240, 14.99 };

    file.write(reinterpret_cast<const char*>(&disc1), sizeof(MusicDisc));
    file.write(reinterpret_cast<const char*>(&disc2), sizeof(MusicDisc));
    file.write(reinterpret_cast<const char*>(&disc3), sizeof(MusicDisc));

    file.close();

    // Друк вмісту файлу
    cout << "Contents of the file after creation:" << endl;
    printFileContent(filename);
    cout << endl;

    // Видалення елемента з індексом 1
    deleteDisc(filename, 1);

    // Друк вмісту файлу після видалення
    cout << "File contents after deletion:" << endl;
    printFileContent(filename);
    cout << endl;

    // Додавання нового елемента
    MusicDisc disc4 = { "Title 4", "Author 4", 195, 11.49 };
    addDisc(filename, disc4);

    // Друк вмісту файлу після додавання
    cout << "File content after adding:" << endl;
    printFileContent(filename);
    cout << endl;

    return 0;
}