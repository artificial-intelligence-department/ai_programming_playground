#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

int countVowels(const std::string& line) {
    int count = 0;
    std::set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (char ch : line) {
        if (vowels.find(ch) != vowels.end()) {
            count++;
        }
    }
    return count;
}

int main() {
    // Створення текстового файлу F1
    std::ofstream f1("F1.txt");
    if (f1.is_open()) {
        f1 << "Shall I compare thee to a summer day?\n";
        f1 << "Thou art more lovely and more temperate\n";
        f1 << "Rough winds do shake the darling buds of May\n";
        f1 << "And summer lease hath all too short a date\n";
        f1 << "Sometime too hot the eye of heaven shines\n";
        f1 << "And often is his gold complexion dimmed\n";
        f1 << "And every fair from fair sometime declines\n";
        f1 << "By chance, or natures changing course, untrimmed\n";
        f1 << "But thy eternal summer shall not fade\n";
        f1 << "Nor shall death brag thou wand rest in his shade\n";
        f1.close();
    } else {
        std::cerr << "Unable to open F1.txt for writing." << std::endl;
        return 1;
    }

 // Копіювати рядки з F1 в F2 без однакових слів
    std::ifstream inputFile("F1.txt");
    std::ofstream outputFile("F2.txt");

    if (inputFile.is_open() && outputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::set<std::string> words;
            std::string word;

            bool hasDuplicate = false;
            while (iss >> word) {
                if (!words.insert(word).second) {
                    hasDuplicate = true;
                    break;
                }
            }

            if (!hasDuplicate) {
                outputFile << line << std::endl;
            }
        }

        inputFile.close();
        outputFile.close();
    } else {
        std::cerr << "Unable to open files." << std::endl;
        return 1;
    }

    // Вивід вмісту файлів F1 і F2
    std::cout << "Content of F1.txt:\n";
    std::ifstream f1Input("F1.txt");
    if (f1Input.is_open()) {
        std::string line;
        while (std::getline(f1Input, line)) {
            std::cout << line << std::endl;
        }
        f1Input.close();
    } else {
        std::cerr << "Unable to open F1.txt for reading." << std::endl;
        return 1; 
    }

    std::cout << "\nContent of F2.txt:\n";
    std::ifstream f2InputDisplay("F2.txt");
    if (f2InputDisplay.is_open()) {
        std::string line;
        while (std::getline(f2InputDisplay, line)) {
            std::cout << line << std::endl;
        }
        f2InputDisplay.close();
    } else {
        std::cerr << "Unable to open F2.txt for reading." << std::endl;
        return 1;
    }

    std::ifstream f2Input("F2.txt");
    if (f2Input.is_open()) {
        std::string firstLine;
        std::getline(f2Input, firstLine);

        int vowelCount = countVowels(firstLine);
        std::cout << "Number of vowels F2: " << vowelCount << std::endl;

        f2Input.close();
    } else {
        std::cerr << "Unable to open F2.txt for vowel count." << std::endl;
        return 1; 
    }

    return 0;
}
