#include <iostream>
#include <fstream>
#include <string>

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    std::ofstream file(name);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot create or open file." << std::endl;
        return Failure;
    }

    file << content;
    file.close();

    return Success;
}

FileOpResult copy_file(const char *file_from, const char *file_to) {
        std::ifstream source_file(file_from, std::ios::binary);
    if (!source_file.is_open()) {
        std::cerr << "Error: Source file does not exist or cannot be opened." << std::endl;
        return Failure;
    }

    std::ofstream destination_file(file_to, std::ios::binary);
    if (!destination_file.is_open()) {
        std::cerr << "Error: Cannot open or create destination file." << std::endl;
        source_file.close();
        return Failure;
    }

    destination_file << source_file.rdbuf();

    if (!destination_file.good()) {
        std::cerr << "Error: Failed to copy content between files." << std::endl;
        source_file.close();
        destination_file.close();
        return Failure;
    }

    source_file.close();
    destination_file.close();

    return Success;
}

int main() {
    const char *source_filename = "source.txt";
    const char *destination_filename = "destination.txt";
    const char *content = "Hello, this is the content of the source file.";

    FileOpResult write_result = write_to_file(source_filename, content);

    if (write_result != Success) {
        std::cerr << "Failed to write content to the source file." << std::endl;
        return 1;
    }

    FileOpResult copy_result = copy_file(source_filename, destination_filename);

    if (copy_result == Success) {
        std::cout << "Files created and copied successfully." << std::endl;
    } else {
        std::cerr << "Failed to copy files." << std::endl;
    }

    return 0;
}
