#include <fstream>
#include <iostream>
#include <string>
using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    ofstream file(name);

    if (!file.is_open()) {
        return Failure;
    }

    file << content;

    if (file.fail()) {
        file.close();
        return Failure;
    }

    file.close();
    return Success;
}

int main() {
    const char *name = "example.txt";
    const char *content = "Hello, this is the content of the file.";

    FileOpResult result = write_to_file(name, content);

    if (result == Success) {
        cout << "Content written to file successfully!" << endl;
    } else {
        cout << "Failed to write to file." << endl;
    }

    return 0;
}
