#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const string& name, const string& content) {
        ofstream file(name);
        if (!file.is_open()) {
            cerr << "Unable to open file: " << name << endl;
            return Failure;
        }
        file << content;
        file.close();
        cout << "Content successfully written to file." << endl;
        return Success;
}

int main() {
    string fileName, content;
    cout << "Enter the file name: ";
    getline(cin, fileName);
    cout << "Enter the content to be written to the file: ";
    getline(cin, content);
    FileOpResult result = write_to_file(fileName, content);
    if (result == Success) {
        cout << "Operation was successful." << endl;
    } else {
        cout << "Operation failed." << endl;
    }
    return 0;
}
