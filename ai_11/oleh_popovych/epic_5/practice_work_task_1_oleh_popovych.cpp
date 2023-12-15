//
// Created by olehio-p on 12/6/2023.
//
#include <fstream>
#include <cstring>
#include <iostream>

enum FileOpResult {
    Success, Failure
};

FileOpResult writeToFile(const char*, const char*);
FileOpResult copyFile(const char*, const char*);

int main(int argc, char const *argv[])
{
    std::string name;
    std::string line;
    std::string content;

    std::cout << "Please enter the file name: ";
    std::cin >> name;
    std::cout << "Please enter the content to write into the file: ";
    std::cin.ignore();
    while(std::getline(std::cin, line) && line != "q") {
        content += line + "\n";
    }
    FileOpResult result = writeToFile(name.c_str(), content.c_str());
    std::cout << result << std::endl;


    std::string src;
    std::string dest;

    std::cout << "Please enter the name of file which to copy: ";
    std::cin >> src;
    std::cout << "Please enter the name of file where to copy: ";
    std::cin >> dest;
    result = copyFile(src.c_str(), dest.c_str());
    std::cout << result << std::endl;
    return 0;
}

FileOpResult writeToFile(const char* name, const char* content) {
    std::ofstream file(name);
    if(file.is_open()) {
        file.write(content, strlen(content));
    } else {
        return Failure;
    }
    file.close();
    return Success;
}

FileOpResult copyFile(const char* fileFrom, const char* fileTo) {
    std::ifstream src(fileFrom);
    std::ofstream dest(fileTo);
    std::string line;

    if(src.is_open() && dest.is_open()) {
        while(std::getline(src, line)) {
            line += '\n';
            dest.write(line.c_str(), line.length());
        }
    } else {
        return Failure;
    }

    src.close();
    dest.close();
    return Success;
}