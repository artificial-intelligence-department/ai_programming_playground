#include <iostream>
#include <fstream>

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char* name, const char* content) {
    std::ofstream file(name);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return Failure;
    }

    file << content;

    if (file.fail()) {
        std::cerr << "Error: Failed to write content to the file." << std::endl;
        file.close();
        return Failure;
    }

    file.close();
    return Success;
}

int main() {
    const char* filename = "example.txt";
    
    std::cout << "Enter content to write to file: ";
    std::string content;
    std::getline(std::cin, content);

    FileOpResult result = write_to_file(filename, content.c_str());

    if (result == Success) {
        std::cout << "File write successful." << std::endl;
    } else {
        std::cout << "File write failed." << std::endl;
    }

    return 0;
}
