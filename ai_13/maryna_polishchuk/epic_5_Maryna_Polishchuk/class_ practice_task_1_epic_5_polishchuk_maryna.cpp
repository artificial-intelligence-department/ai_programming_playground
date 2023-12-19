#include <fstream>
#include <iostream>
#include <string>
using namespace std;

enum FileOpResult {Success, Fail};

FileOpResult write_to_file(string name, const string &content) {
    ofstream file(name); // Use ofstream for writing to a file

    if (!file.is_open()) {
        return Fail; // If file creation fails, return Failure
    }

    file << content;

    if (file.fail()) {
        cout << "Failed to write text ";
        file.close();
        return Fail;
    }

    cout << "File was opened successfully";
    file.close();
    return Success;
}

int main() {
    string content, name = "MyName";
    cout << "write some text: ";
    getline(cin, content);

    FileOpResult result = write_to_file(name, content);

    if (result == Success) {
        cout << "Content written to file successfully!" << endl;
    } else {
        cout << "Failed to write to file." << endl;
    }

    return 0;
}


