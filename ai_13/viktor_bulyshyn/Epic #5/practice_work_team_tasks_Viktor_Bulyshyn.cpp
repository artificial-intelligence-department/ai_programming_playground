#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Перерахування для результатів операцій з файлом
enum FileOpResult { Success, Failure };

// Функція для запису вмісту у файл
FileOpResult write_to_file(const string& filename, const string& content) {
    // Відкриття файлу для запису
    ofstream file(filename);

    // Перевірка, чи файл успішно відкрито
    if (!file.is_open()) {
        return Failure;
    }

    // Запис вмісту у файл
    file << content;
    // Закриття файлу
    file.close();

    // Перевірка, чи не виникли помилки під час запису
    if (file.fail()) {
        return Failure;
    }

    return Success;
}

int main() {
    string filename, content;

    // Введення ім'я файлу від користувача
    cout << "Enter the name of the file: ";
    cin >> filename;

    // Ігнорування залишкових символів в буфері введення
    cin.ignore();

    // Введення вмісту файлу від користувача
    cout << "Enter the content to write to the file: ";
    getline(cin, content);

    // Виклик функції для запису вмісту у файл і виведення результату
    if (write_to_file(filename, content) == Success) {
        cout << "Success\n";
    } else {
        cout << "Failure\n";
    }

    return 0;
}
