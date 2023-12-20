#include <iostream>
#include <fstream>
#include <string>

int countVowels(const std::string& line) {
    int vowelsCount = 0;
    std::string vowels = "aeiouAEIOU";
    
    for (char c : line) {
        if (vowels.find(c) != std::string::npos) {
            vowelsCount++;
        }
    }
    
    return vowelsCount;
}

int main() {
    std::ifstream inputFile("F1.txt");
    std::ofstream outputFile("F2.txt");
    std::string line;
    int maxVowels = 0;
    int maxVowelsLine = 0;
    int lineNumber = 0;
    
    while (std::getline(inputFile, line)) {
        lineNumber++;
        
        int vowelsCount = countVowels(line);
        
        if (vowelsCount > maxVowels) {
            maxVowels = vowelsCount;
            maxVowelsLine = lineNumber;
        }
        
        // Копіюємо рядки в файл F2, крім рядка з найбільшою кількістю голосних букв
        if (lineNumber != maxVowelsLine) {
            outputFile << line << std::endl;
        }
    }
    
    inputFile.close();
    outputFile.close();
    
    std::cout << "Line number with the largest number of vowels: " << maxVowelsLine << std::endl;
    
    return 0;
}