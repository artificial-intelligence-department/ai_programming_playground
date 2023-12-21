#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    ofstream file(name);

    if (!file.is_open()) {
        return FileOpResult::Failure;
    }

    file << content;
    file.close();

    return FileOpResult::Success;
}

FileOpResult copy_file(const char *file_from, const char *file_to) {
    ifstream source(file_from, ios::binary);
    ofstream destination(file_to, ios::binary);

    if (!source.is_open() || !destination.is_open()) {
        return FileOpResult::Failure;
    }

    destination << source.rdbuf();

    source.close();
    destination.close();

    return FileOpResult::Success;
}

int main() {
    // Задача  №1
    const char *filename1 = "file1.txt";
    const char *content = "Elon Musk versus Mark Zukerberg";

    if (write_to_file(filename1, content) == FileOpResult::Success) {
        cout << "File created and content written successfully.\n";
    } else {
        cerr << "Failed to create or write to the file.\n";
    }

    // Задача №2
    const char *filename2 = "file2.txt";
    
    if (copy_file(filename1, filename2) == FileOpResult::Success) {
        cout << "File content copied successfully.\n";
    } else {
        cerr << "Failed to copy file content.\n";
    }

    return 0;
}
