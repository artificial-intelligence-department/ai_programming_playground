#include <iostream>
#include <fstream>

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char *file_from, const char *file_to) {
    // Check if file_from or file_to is null
    if (!file_from || !file_to) {
        return Failure;
    }

    // Open the source file for reading
    std::ifstream source(file_from, std::ios::binary);

    // Check if the source file is successfully opened
    if (!source.is_open()) {
        return Failure;
    }

    // Open the destination file for writing
    std::ofstream destination(file_to, std::ios::binary);

    // Check if the destination file is successfully opened
    if (!destination.is_open()) {
        // Close the source file before returning
        source.close();
        return Failure;
    }

    // Copy the contents of the source file to the destination file
    destination << source.rdbuf();

    // Close both files
    source.close();
    destination.close();

    // Check if both files are successfully closed
    if (source.fail() || destination.fail()) {
        return Failure;
    }

    return Success;
}

int main() {
    const char *file_from = "source.txt";
    const char *file_to = "destination.txt";

    FileOpResult result = copy_file(file_from, file_to);

    if (result == Success) {
        std::cout << "File copy successful!\n";
    } else {
        std::cout << "File copy failed!\n";
    }

    return 0;
}
