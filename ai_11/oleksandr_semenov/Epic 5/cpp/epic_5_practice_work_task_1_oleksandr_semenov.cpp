#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    // Перевірка вхідних параметрів
    if (name == nullptr || content == nullptr) {
       cerr << "Invalid input parameters\n";
        return Failure;
    }

    // Формування повного шляху для файла
   string fullPath = "D:\\practice 5\\" +string(name);

    // Відкриття файлу для запису
   ofstream file(fullPath);

    // Перевірка, чи вдалося відкрити файл
    if (!file.is_open()) {
       cerr << "Failed to open file: " << fullPath <<endl;
        return Failure;
    }

    // Запис вмісту у файл
    file << content <<endl;

    // Перевірка, чи вдалося записати дані
    if (file.fail()) {
       cerr << "Failed to write content to file\n";
        return Failure;
    }

    // Закриття файлу
    file.close();

    // Перевірка, чи вдалося закрити файл
    if (file.fail()) {
       cerr << "Failed to close file\n";
        return Failure;
    }

    // Успішне виконання операції
    return Success;
}

int main() {
    const char *filename = "example.txt";
    const char *content = "Hello, world!";

    FileOpResult result = write_to_file(filename, content);

    if (result == Success) {
       cout << "File write operation successful\n";
    } else {
       cerr << "File write operation failed\n";
    }

    return 0;
}
