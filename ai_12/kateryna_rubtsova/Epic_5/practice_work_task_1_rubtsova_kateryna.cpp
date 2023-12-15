#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *filename, const char *content) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "File couldn't be opened or created.\n";
        return Failure;
    }
    file << content;
    file.close();
    cout << "File created and written successfully.\n";
    return Success;
}

FileOpResult copy_file(const char *file_from, const char *file_to) {
    ifstream source(file_from);
    ofstream destination(file_to);
    if (!source.is_open()) {
        cout << "Source file couldn't be opened.\n";
        return Failure;
    }
    if (!destination.is_open()) {
        cout << "Destination file couldn't be opened or created.\n";
        source.close();
        return Failure;
    }
    char info;
    while (source.get(info)) {
        destination.put(info);
    }
    source.close();
    destination.close();
    cout << "File copied successfully.\n";
    return Success;
}

int main() {
    string write_filename, write_content, copy_filename, destination_filename;
    cout << "Enter the filename for writing: ";
    getline(cin, write_filename);
    cout << "Enter the content: ";
    getline(cin, write_content);
    cout << "Enter the filename to copy: ";
    getline(cin, copy_filename);
    cout << "Enter the destination filename: ";
    getline(cin, destination_filename);
    FileOpResult result_write = write_to_file(write_filename.c_str(), write_content.c_str());
    FileOpResult result_copy = copy_file(copy_filename.c_str(), destination_filename.c_str());
    if (result_write == Success) {
        cout << "Success.\n";
    } else {
        cout << "Failure.\n";
    }
    if (result_copy == Success) {
        cout << "Success.\n";
    } else {
        cout << "Failure.\n";
    }



    return 0;
}