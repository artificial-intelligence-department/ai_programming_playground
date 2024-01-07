#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char* name, const char* content) {
    if (!name || !content) {
        cerr << "Invalid input: Name or content is null." << endl;
        return Failure;
    }

    ofstream file(name);

    if (!file.is_open()) {
        cerr << "Error opening file: " << name << endl;
        return Failure;
    }

    file << content;

    if (file.fail()) {
        cerr << "Error writing to file." << endl;
        file.close(); 
        return Failure;
    }

    file.close();

    return Success;
}

int main() {
    const char* filename = "source.txt";
    string fileContent;

    cout << "Enter content: ";
    getline(cin, fileContent);

    FileOpResult result = write_to_file(filename, fileContent.c_str());

    if (result == Success) {
        cout << "File successfully created or updated." << endl;
    } else {
        cout << "Failed to create or update the file." << endl;
    }

    return 0;
}
