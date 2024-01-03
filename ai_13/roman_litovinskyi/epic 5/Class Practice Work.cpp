#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Перерахування для результату операцій з файлом
enum class FileOpResult { Success, Failure };

// Функція для запису вмісту у файл
FileOpResult write_to_file(const string& name, const string& content) {
    // Перевірка на пустість назви файлу чи вмісту
    if (name.empty() || content.empty()) {
        return FileOpResult::Failure;
    }

    // Відкриття файлу для запису
    ofstream file(name, ios::out);
    if (!file.is_open()) { // Перевірка на успішне відкриття файлу
        return FileOpResult::Failure;
    }

    // Запис вмісту у файл
    file << content;

    return FileOpResult::Success;
}

int main() {
    string filename = "classpractice.txt"; // Назва файлу
    string content; // Змінна для зберігання вмісту

    cout << "Enter content to write to the file: "; // Просимо користувача ввести вміст для запису
    getline(cin, content); // Отримуємо вміст від користувача

    FileOpResult result = write_to_file(filename, content); // Виклик функції для запису у файл

    // Перевірка результату операції з файлом та виведення відповідного повідомлення
    if (result == FileOpResult::Success) {
        cout << "Write to file successful." << endl;
    } else {
        cout << "Failed to perform file operation." << endl;
    }

    return 0;
}
