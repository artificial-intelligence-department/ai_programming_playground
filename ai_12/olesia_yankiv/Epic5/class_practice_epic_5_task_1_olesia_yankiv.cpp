#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const string& file_from, const string& file_to) {
    ifstream source(file_from, ios::binary);
    if (!source.is_open()) {
        return Failure; // Failed to open source file
    }

    ofstream destination(file_to, ios::binary);
    if (!destination.is_open()) {
        source.close();
        return Failure; // Failed to create or open destination file
    }

    destination << source.rdbuf();

    source.close();
    destination.close();

    return Success;
}

int main() {
    string source_file, destination_file;

    cout << "Enter source file path: ";
    getline(cin, source_file);

    cout << "Enter destination file path: ";
    getline(cin, destination_file);

    FileOpResult result = copy_file(source_file, destination_file);

    if (result == Success) {
        cout << "File copied successfully!\n";
    } else {
        cout << "File copy operation failed!\n";
    }

    return 0;
}
