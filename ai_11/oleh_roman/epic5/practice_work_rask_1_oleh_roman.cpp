#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult {
    Success,
    Failure
};

FileOpResult write_to_file(const char *name, const char *content) {
    ofstream file(name);

    if (!file.is_open()) {
        return FileOpResult::Failure;
    }

    file << content;

    if (file.fail()) {
        file.close();
        return FileOpResult::Failure;
    }

    file.close();

    return FileOpResult::Success;
}

int main() {
    string content;
    cout << "Введіть текст:";
    getline(cin, content);

    FileOpResult result = write_to_file("file_from.txt", content.c_str());

    if (result == FileOpResult::Success) {
        cout << "Success" << endl;
    } else {
        cout << "Failure" << endl;
    }

    return 0;
}
