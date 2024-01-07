#include <fstream>
#include <iostream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(char *name, char *content) {
    ofstream file(name);
    if (!file.is_open()) {
        return Failure;
    }

    file << content;

    if (file.fail()) {
        return Failure;
    }

    file.close();
    if (file.fail()) {
        return Failure;
    }

    return Success;
}

int main() {
    char name[100];
    char content[1000];

    cout << "Enter file name: ";
    cin.getline(name, 100);

    cout << "Enter content: ";
    cin.getline(content, 1000);

    FileOpResult result = write_to_file(name, content);
    if (result == Success) {
        cout << "File written successfully." << endl;
    } else {
        cout << "Failed to write to file." << endl;
    }

    return 0;
}