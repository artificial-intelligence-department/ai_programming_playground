//
// Created by olehio-p on 12/7/2023.
//
#include <fstream>
#include <iostream>
#include <sstream>

int createFile(const std::string&, const std::string&);
void copyLines(const std::string&, const std::string&);
void printFile(const std::string&);

int main(int argc, char const *argv[])
{
    std::string input = "Hello, world\nHeaven\nBrotherhood is everything\nHome";
    std::string file1 = "f1.txt";
    std::string file2 = "f2.txt";
    createFile(file1, input);
    copyLines(file1, file2);

    std::cout << "The content of file 1:" << std::endl;
    printFile(file1);
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "The content of file 2:" << std::endl;
    printFile(file2);
    return 0;
}

int createFile(const std::string& filename, const std::string& content) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Unable to open this file" << std::endl;
        return -1;
    }
    outFile.write(content.c_str(), content.length());
    return 0;
}

void copyLines(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Unable to open the files." << std::endl;
        return;
    }

    std::string line;
    std::string word;
    int counter;
    while (std::getline(inFile, line)) {
        counter = 0;
        std::stringstream ss(line);
        while(std::getline(ss, word, ' ')) {
            counter++;
        }
        if(counter == 1) {
            line += "\n";
            outFile.write(line.c_str(), line.length());
        }
    }

    inFile.close();
    outFile.close();
}

void printFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Unable to open this file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }
    inFile.close();
}
