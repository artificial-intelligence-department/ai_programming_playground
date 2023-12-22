#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct VideoCassette {
    string title;
    string director;
    string duration;
    double price;
};

void createTextFile(const vector<VideoCassette>& data, const char* filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& cassette : data) {
            file << cassette.title << "\n";
            file << cassette.director << "\n";
            file << cassette.duration << "\n";
            file << cassette.price << "\n";
            file << "===\n"; // Роздільник між записами
        }
        file.close();
        cout << "Створено текстовий файл " << filename << endl;
    } else {
        cout << "Помилка при створенні файлу" << endl;
    }
}

void readTextFile(const char* filename) {
    ifstream file(filename);
    if (file.is_open()) {
        VideoCassette cassette;
        while (getline(file, cassette.title)) {
            getline(file, cassette.director);
            getline(file, cassette.duration);
            file >> cassette.price;
            file.ignore(); // Ігноруємо символ нового рядка
            string delimiter;
            getline(file, delimiter); // Отримуємо роздільник
            if (delimiter == "===") {
                cout << "Назва: " << cassette.title << ", Режисер: " << cassette.director
                     << ", Тривалість: " << cassette.duration << ", Ціна: " << cassette.price << endl;
            }
        }
        file.close();
    } else {
        cout << "Помилка при зчитуванні файлу" << endl;
    }
}

void deleteByPrice(vector<VideoCassette>& data, double maxPrice, const char* filename) {
    auto it = remove_if(data.begin(), data.end(), [maxPrice](const VideoCassette& cassette) {
        return cassette.price > maxPrice;
    });
    if (it != data.end()) {
        data.erase(it, data.end());
        createTextFile(data, filename);
        cout << "Видалено відеокасети з ціною вище " << maxPrice << endl;
    } else {
        cout << "Немає відеокасетів з ціною вище " << maxPrice << endl;
    }
}

void addNewCassettes(vector<VideoCassette>& data, const char* filename) {
    for (int i = 0; i < 3; ++i) {
        VideoCassette newCassette;
        cout << "Введіть назву фільму: ";
        getline(cin, newCassette.title);
        
        cout << "Введіть режисера: ";
        getline(cin, newCassette.director);
        
        cout << "Введіть тривалість: ";
        getline(cin, newCassette.duration);
        
        cout << "Введіть ціну: ";
        cin >> newCassette.price;
        cin.ignore(); // Очищення буфера введення
        
        data.push_back(newCassette);
    }
    createTextFile(data, filename);
    cout << "Додано 3 нові відеокасети до файлу" << endl;
}

int main() {
    vector<VideoCassette> data;

    char choice;
    do {
        VideoCassette newCassette;
        cout << "Введіть назву фільму: ";
        getline(cin, newCassette.title);
        
        cout << "Введіть режисера: ";
        getline(cin, newCassette.director);
        
        cout << "Введіть тривалість: ";
        getline(cin, newCassette.duration);
        
        cout << "Введіть ціну: ";
        cin >> newCassette.price;
        cin.ignore(); // Очищення буфера введення
        
        data.push_back(newCassette);
        
        cout << "Бажаєте ввести ще один фільм? (y/n): ";
        cin >> choice;
        cin.ignore(); // Очищення буфера введення
    } while (choice == 'y' || choice == 'Y');

    createTextFile(data, "videocassettes.txt"); // Запис у файл

    double deletePrice;
    cout << "Введіть ціну для видалення відеокасет: ";
    cin >> deletePrice;
    cin.ignore(); // Очищення буфера введення

    deleteByPrice(data, deletePrice, "videocassettes.txt"); // Видалення за ціною

    addNewCassettes(data, "videocassettes.txt"); // Додавання нових відеокасетів

    return 0;
}