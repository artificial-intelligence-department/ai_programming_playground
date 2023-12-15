#include <fstream>
#include <string>
#include <iostream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(string, string);

int main() {
       cout << "Enter name: ";
        string name;
    getline(cin, name);
    cout << "Enter content: ";
    string content;
    getline(cin, content);
    
    FileOpResult result = write_to_file(name, content);
    if (result == Success) {
        cout << "File was written successfully.\n";
    } else {
        cout << "Failed to write to file.\n";
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
