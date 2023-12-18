#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    if (name == nullptr || content == nullptr) {
        cerr << "Невірні вхідні параметри." << endl;
        return Failure;
    }

    ofstream file(name);
    
    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу " << name << endl;
        return Failure;
    }

    file << content;

    if (file.fail()) {
        cerr << "Помилка запису до файлу." << endl;
        file.close();
        return Failure;
    }

    file.close();
    return Success;
}

int main() {
    const char *filename = "example.txt";

    cout << "Введіть текст для запису у файл: ";
    string input_content;
    getline(cin, input_content);

    FileOpResult result = write_to_file(filename, input_content.c_str());

    if (result == Success) {
        cout << "Файл успішно створено та записано " << endl;
    } else {
        cerr << "Не вдалося створити або записати файл" << endl;
    }

    return 0;
}
