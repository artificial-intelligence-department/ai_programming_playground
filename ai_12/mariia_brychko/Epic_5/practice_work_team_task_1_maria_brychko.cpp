#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    ofstream file(name); // Спроба створити файл з заданим ім'ям

    if (!file.is_open()) {
        cerr << "Failed to create/open file." << endl;
        return Failure;
    }

    file << content; // Записати вміст стрічки у файл

    file.close(); // Закрити файл

    return Success;
}

int main() {
    const char* filename = "class_practice_1.txt"; // Ім'я файлу
    const char* content = "Purpose of the task is understanding methods of working with files: Implementation of the function of creating and writing to a file will help to master the practical skills of working with files using the C++ standard library."; // Зміст для запису

    FileOpResult result = write_to_file(filename, content);

    if (result == Success) {
        cout << "Writing to file completed successfully." << endl;
    } else {
        cout << "Failed to write to file." << endl;
    }

    return 0;
}
