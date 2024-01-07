#include <iostream>
#include <fstream>

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    std::ofstream file;
    file.open(name);

    if (!file.is_open()) {
        return FileOpResult::Failure;
    }

    file << content;
    file.close();
    return FileOpResult::Success;
}

int main() {
    const char *filename = "example.txt";
    
    std::cout << "Enter text to write to the file:\n";
    std::string userText;
    std::getline(std::cin, userText);

    FileOpResult result = write_to_file(filename, userText.c_str());

    if (result == FileOpResult::Success) {
        std::cout << "Text successfully written to the file.\n";
    } else {
        std::cout << "Error writing to the file.\n";
    }

    return 0;
}