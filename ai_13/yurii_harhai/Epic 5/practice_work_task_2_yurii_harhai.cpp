#include <fstream>
#include <string>
#include <iostream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(string, string);
FileOpResult copy_file(string, string);

int main() {
    cout << "Enter content: ";
    string content;
    getline(cin, content);
    
    FileOpResult result = write_to_file("file_from", content);
    if (result == Success) {
        cout << "File 'file_from' was written successfully.\n";
    } else {
        cout << "Failed to write to file 'file_from'.\n";
    }

    result = copy_file("file_from", "file_to");
    if (result == Success) {
        cout << "File 'file_to' was written successfully.\n";
    } else {
        cout << "Failed to write to file 'file_to'.\n";
    }
    return 0;
}

FileOpResult write_to_file(string name, string content) {
    ofstream file(name);
    if (!file) {
        return Failure;
    }
    file << content;
    if (!file) {
        return Failure;
    }
    file.close();
    if (!file) {
        return Failure;
    }
    return Success;
}

FileOpResult copy_file(string from, string to) {
    ifstream src(from, ios::binary);
    ofstream dst(to, ios::binary);
    dst << src.rdbuf();
    return src && dst ? Success : Failure;
}
