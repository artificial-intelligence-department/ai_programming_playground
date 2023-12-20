#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <vector>

int main() {
    std::vector<std::string> lines; // Вектор для зберігання введених рядків
    std::string line;

    // Введення рядків вручну
    std::cout << "Enter the lines:\n";
    while (std::getline(std::cin, line) && !line.empty()) {
        lines.push_back(line);
    }

    std::ofstream f1OutputFile("F1.txt"); // Вихідний файл F1
    std::ofstream f2OutputFile("F2.txt"); // Вихідний файл F2

    if (!f1OutputFile.is_open() || !f2OutputFile.is_open()) {
        std::cerr << "Can't open the file!" << std::endl;
        return 1;
    }

    std::unordered_set<std::string> uniqueWords;
    std::vector<std::string> duplicateLines;

    for (const auto& inputLine : lines) {
        f1OutputFile << inputLine << std::endl; // Запис у файл F1

        std::istringstream iss(inputLine);
        std::unordered_set<std::string> lineWords;

        std::string word;
        while (iss >> word) {
            if (!lineWords.insert(word).second) {
                // Знайдено дублікат слів у рядку
                duplicateLines.push_back(inputLine);
                break;
            }
        }
    }

    // Записуємо рядки з дублікатами слів у файл F2
    for (const auto& duplicateLine : duplicateLines) {
        f2OutputFile << duplicateLine << std::endl;
    }

    std::cout << "Saved in  F1.txt and F2.txt." << std::endl;

    return 0;
}
