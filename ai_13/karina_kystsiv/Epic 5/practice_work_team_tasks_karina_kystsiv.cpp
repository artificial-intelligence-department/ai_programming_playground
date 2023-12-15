#include <iostream>
#include <fstream>
#include <string>

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const std::string& name, const std::string& content);
FileOpResult copy_file(const std::string& file_from, const std::string& file_to);

int main() {
    std::string fileName, text;
    
    // Writing to file
    std::cout << "Enter name of the file you want to write to: ";
    std::getline(std::cin, fileName);
    std::cout << "Enter text you want to write into the file: ";
    std::getline(std::cin, text);

    if (write_to_file(fileName, text) == Success) {
        std::cout << "Write to file: Success\n";
    } else {
        std::cout << "Write to file: Failure\n";
    }

    // Copying files
    std::string fileNameForCopy, fileNamtoCopy;
    
    std::cout << "Enter name of the file you want to copy from: ";
    std::getline(std::cin, fileNameForCopy);
    std::cout << "Enter name of the file you want to copy this into: ";
    std::getline(std::cin, fileNamtoCopy);

    if (copy_file(fileNameForCopy, fileNamtoCopy) == Success) {
        std::cout << "Copy file: Success\n";
    } else {
        std::cout << "Copy file: Failure\n";
    }

    return 0;
}

FileOpResult write_to_file(const std::string& name, const std::string& content) {
    std::ofstream myFile(name);

    if (!myFile.is_open()) {
        return Failure;
    }

    myFile << content;

    if (myFile.fail()) {
        myFile.close();
        return Failure;
    }

    myFile.close();
    return Success;
}

FileOpResult copy_file(const std::string& file_from, const std::string& file_to) {
    std::ifstream myReadFile(file_from);
    std::ofstream myCopiedFile(file_to);

    if (!myReadFile.is_open() || !myCopiedFile.is_open()) {
        return Failure;
    }

    std::string myText;
    while (std::getline(myReadFile, myText)) {
        myCopiedFile << myText << "\n";
    }

    myReadFile.close();
    myCopiedFile.close();
    return Success;
}
