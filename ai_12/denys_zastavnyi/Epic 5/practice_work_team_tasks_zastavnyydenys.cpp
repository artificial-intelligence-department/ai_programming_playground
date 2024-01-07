#include <iostream>
#include <fstream>

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    std::ofstream file(name);

    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << name << std::endl;
        return Failure;
    }

    file << content;

    if (!file.good()) {
        std::cerr << "Error writing to file: " << name << std::endl;
        return Failure;
    }

    file.close();

    return Success;
}

int main() {
    const char *filename = "example.txt";
    const char *content = "Hello, world!";

    FileOpResult result = write_to_file(filename, content);

    if (result == Success) {
        std::cout << "File created and written successfully." << std::endl;
    } else {
        std::cerr << "Failed to create or write to file." << std::endl;
    }

    return 0;
}