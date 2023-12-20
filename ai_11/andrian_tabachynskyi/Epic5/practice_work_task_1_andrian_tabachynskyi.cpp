#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult {
    Success,
    Failure
};

FileOpResult writetofile(const char* name, const char* content) {

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

    cout << "Write a text:";
    getline(cin, content);


    FileOpResult result = writetofile("F1.txt", content.c_str());

    if (result == FileOpResult::Success) {
        cout << "Success" << endl;
    }
    else {
        cout << "Failure" << endl;
    }

    return 0;
}
