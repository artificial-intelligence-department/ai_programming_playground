#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(char* file_from, char* file_to) {

    ifstream from_file(file_from, ios::binary);

    if (!from_file.is_open()) {
        return Failure;
    }

    ofstream to_file(file_to, ios::binary);

    if (!to_file.is_open()) {
        return Failure;
    }

    to_file << from_file.rdbuf();

    if (from_file.fail() || to_file.fail()) {
        return Failure;
    }

    return Success;
}

int main() {

    char from_file[250];
    char to_file[250];

    cout << "Enter the name of file from which you want to copy content: ";
    cin >> from_file;

    cout << "Enter the name of file to which you want to copy content: ";
    cin >> to_file;

    FileOpResult result = copy_file(from_file, to_file);

    if (result == Success) {
        cout << "Content of file: " << "\"" << from_file << "\"" <<  " is successfully copied to file " << "\"" << to_file << "\"."<< "\n";
    } else {
        cout << "ERROR\n";
    }

    return 0;
} 