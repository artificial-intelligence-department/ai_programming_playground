#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char *file_from, const char *file_to) {
    ifstream source(file_from);

    if (!source.is_open()) {
        return Failure; // Unable to open source file
    }

    ofstream destination(file_to);

    if (!destination.is_open()) {
        source.close();
        return Failure; // Unable to open or create destination file
    }

    string line;
    while (getline(source, line)) {
        destination << line << endl;
    }

    if (source.fail() || destination.fail()) {
        source.close();
        destination.close();
        return Failure; // Failed to read from source or write to destination
    }

    source.close();
    destination.close();
    return Success;
}

int main() {
    const char *file_from = "file_from.txt";
    const char *file_to = "file_to.txt";

    FileOpResult result = copy_file(file_from, file_to);

    if (result == Success) {
        cout << "File copied successfully!" << endl;
    } else {
        cout << "Failed to copy file." << endl;
    }

    return 0;
}
