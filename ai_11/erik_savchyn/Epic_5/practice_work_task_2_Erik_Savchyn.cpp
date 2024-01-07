#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>

using namespace std;

enum FileOpResult { Success, Failure, InvalidInput, InvalidExtension };

FileOpResult write_to_file(const char *name, const char *content) {
    if (name == nullptr || content == nullptr) {
        return InvalidInput;
    }

    if (strlen(content) == 0) {
        return InvalidInput;
    }

    const char *extension = strrchr(name, '.');
    if (extension == nullptr || strcmp(extension, ".txt") != 0) {
        return InvalidExtension;
    }

    ofstream file(name);
    if (!file.is_open()) {
        return Failure;
    }

    file << content;

    if (file.fail()) {
        file.close();
        return Failure;
    }

    file.close();

    return Success;
}

int main() {
    cout << "Введіть ім'я файлу: ";
    string filename;
    getline(cin, filename);

    cout << "Введіть вміст стрічки для запису в файл: ";
    string content;
    getline(cin, content);

    FileOpResult result = write_to_file(filename.c_str(), content.c_str());

    switch (result) {
        case Success:
            cout << "File successfully created and written." << endl;
            break;
        case Failure:
            cout << "File operation failed." << endl;
            break;
        case InvalidInput:
            cout << "Invalid input provided." << endl;
            break;
        case InvalidExtension:
            cout << "Invalid file extension. Only .txt files are allowed." << endl;
            break;
    }

    return 0;
}