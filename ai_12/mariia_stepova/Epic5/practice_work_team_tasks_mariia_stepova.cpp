#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    if (!name || !content) {
        return Failure; // Невірні вхідні параметри
    }

    ofstream file(name, ios::out); // Створення об'єкту файлу для запису

    if (!file.is_open()) {
        return Failure; // Помилка відкриття файлу
    }

    file << content; // Запис вмісту у файл

    file.close(); // Закриття файлу

    if (file.fail()) {
        return Failure; // Помилка під час запису
    }

    return Success; // Успішно завершено запис
}

int main() {
    const char* filename = "example.txt";
    const int maxContentLength = 1000;
    char content[maxContentLength];

    cout << "Введіть вміст для запису у файл: ";
    cin.getline(content, maxContentLength); // Зчитування вмісту зі стандартного вводу

    FileOpResult result = write_to_file(filename, content);

    if (result == Success) {
        cout << "Файл успішно створено та записано!\n";
    } else {
        cout << "Помилка при створенні або записі файлу.\n";
    }

    return 0;
}