#include <iostream>
#include <fstream>
using namespace std;
enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char* name, const char* content) {
    if (name == nullptr || content == nullptr) {
        cerr << "Invalid input parameters.\n";
        return Failure;
    }

    ofstream file(name, ios::out);

    if (!file.is_open()) {
        cerr << "Failed to open file " << name << " for writing.\n";
        return Failure;
    }

    file << content;

    if (file.fail()) {
        cerr << "Failed to write content to file " << name << ".\n";
        file.close();
        return Failure;
    }

    file.close();

    return Success;
}

int main() {
    const char* filename = "example.txt";
    const char* content = "Hello, World!";

    FileOpResult result = write_to_file(filename, content);

    if (result == Success) 
        cout << "Success.\n";
    else 
        cerr << "fail.\n";

    return 0;
}
