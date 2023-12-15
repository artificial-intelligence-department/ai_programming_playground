#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    ofstream file(name);

    if (!file.is_open()) {
        return Failure;
    }

    file << content << endl;

    if (file.fail()) {
        file.close();
        return Failure;
    }

    file.close();

    return Success;
}

int main() {
    const char *file_name = "example.txt";
    char content[100];

    cout << "Enter content to write to the file: ";
    cin.getline(content, sizeof(content));

    FileOpResult result = write_to_file(file_name, content);

    if (result == Success) {
        cout << "Success." << endl;
    } else {
        cout << "Failure." << endl;
    }

    return 0;
}
