#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const std::string &content) {
    std::ofstream outputFile(name, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file: " << name << std::endl;
        return Failure;
    }

    outputFile << content << std::endl;
    outputFile.close();
    return Success;
}

FileOpResult read_and_copy(const char *inputFile, const char *outputFile) {
    std::ifstream inputFileStream(inputFile);
    std::ofstream outputFileStream(outputFile);

    if (!inputFileStream.is_open() || !outputFileStream.is_open()) {
        std::cerr << "Error opening files." << std::endl;
        return Failure;
    }

    std::string line;
    size_t i = 0;
    while (std::getline(inputFileStream, line)) {
        std::cout << i << ". " << line << std::endl;
        i++;
    }

    size_t start, end;
    std::cout << "Enter the range of the lines you want to check before copying:" << std::endl;
    std::cin >> start >> end;

    inputFileStream.close();
    inputFileStream.open(inputFile);

    size_t x = 0;
    while (std::getline(inputFileStream, line)) {
        if (line.find('a') == std::string::npos && line.find('A') == std::string::npos && x > start && x < end) {
            outputFileStream << line << std::endl;
        }
        x++;
    }

    inputFileStream.close();
    outputFileStream.close();
    return Success;
}

void delete_files(const char *file1, const char *file2) {
    if (std::filesystem::exists(file1)) {
        std::filesystem::remove(file1);
    }

    if (std::filesystem::exists(file2)) {
        std::filesystem::remove(file2);
    }
}

int count_vowels(const std::string& line) {
    int count = 0;
    for (char ch : line) {
        if (std::tolower(ch) == 'a' || std::tolower(ch) == 'e' || std::tolower(ch) == 'i' ||
            std::tolower(ch) == 'o' || std::tolower(ch) == 'u') {
            count++;
        }
    }
    return count;
}

std::string most_vowels(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return "";
    }

    std::string line;
    std::string line_with_most_vowels;
    int max_vowels = 0;

    while (std::getline(file, line)) {
        int vowels_count = count_vowels(line);
        if (vowels_count > max_vowels) {
            max_vowels = vowels_count;
            line_with_most_vowels = line;
        }
    }

    file.close();
    return line_with_most_vowels;
}

int main() {
    std::string content;
    const char *f1 = "f1.txt";
    const char *f2 = "f2.txt";
    delete_files(f1, f2);

    std::cout << "Enter the content of the file:" << std::endl;

    for (int i = 0; i < 10; i++) {
        std::getline(std::cin, content);
        write_to_file(f1, content);
    }

    FileOpResult result = read_and_copy(f1, f2);

    if (result == Success) {
        std::cout << "File copied successfully" << std::endl;
    } else {
        std::cerr << "Error copying file." << std::endl;
    }

    std::string vowels = most_vowels(f2);
    std::cout << "Line with the most vowels:" << std::endl << vowels;

    return 0;
}
