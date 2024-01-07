#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum class FileOpResult { Success, Failure };

FileOpResult write_to_file(const string& name, const string& content) {
    if (name.empty() || content.empty()) {
        return FileOpResult::Failure;
    }

    ofstream file(name, ios::out);
    if (!file.is_open()) {
        return FileOpResult::Failure;
    }

    file << content;

    return FileOpResult::Success;
}

int main() {
    string filename = "classpractice.txt";
    string content;

    cout << "Enter content to write to the file: ";
    getline(cin, content);

    FileOpResult result = write_to_file(filename, content);

    if (result == FileOpResult::Success) {
        cout << "Write to file successful." << endl;
    } else {
        cout << "Failed to perform file operation." << endl;
    }

    return 0;
}
