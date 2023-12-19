#include <iostream>
#include <fstream>
#include <string>
using namespace std;
enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const string& name, const string& content) {
    ofstream file(name);
    if (!file.is_open()) {
        return Failure;
    }

    file << content;
    file.close();

    return Success;
}

FileOpResult copy_file(const string& file_from, const string& file_to) {
    ifstream source(file_from, ios::binary);
    if (!source.is_open()) {
        return Failure;
    }

    ofstream destination(file_to, ios::binary);
    if (!destination.is_open()) {
        source.close();
        return Failure;
    }

    destination << source.rdbuf();
    source.close();
    destination.close();

    return Success;
}

int main() {
    // Записати стрічку у файл
    string name = "test.txt";
    string content;

    cout << "Enter the text to write to the file: ";
    getline(cin, content);

    FileOpResult result = write_to_file(name, content);
    if (result == Success) {
        cout << "File created and saved successfully." << endl;
    } else {
        cout << "An error occurred while creating or writing to the file." << endl;
    }

    // Скопіювати вміст файлу
    string file_from, file_to;
    cout << "Enter the path to the file you want to copy: ";
    getline(cin, file_from);
    cout << "Enter the path to the new file to copy to: ";
    getline(cin, file_to);

    result = copy_file(file_from, file_to);
    if (result == Success) {
        cout << "File copied successfully." << endl;
    } else {
        cout << "An error occurred while copying the file." << endl;
    }

    return 0;
}
