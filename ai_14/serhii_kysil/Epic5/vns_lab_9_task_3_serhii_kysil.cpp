#include <iostream>
#include <fstream>
#include <string>
int main() {
    // Відкриваємо файл F1 для читання
    std::ifstream inputFile("F1.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Fail F1.txt" << std::endl;
        return 1;
    }
    // Відкриваємо файл F2 для запису
    std::ofstream outputFile("F2.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Fail F2.txt" << std::endl;
        inputFile.close();  // Закриваємо файл F1 перед виходом
        return 1;
    }
    std::string line;
    int totalCharactersInF2 = 0;
    while (std::getline(inputFile, line)) {
        // Перевіряємо, чи рядок починається і закінчується на ту саму букву
        if (!line.empty() && line.front() == line.back()) {
            // Записуємо поточний рядок у файл F2
            outputFile << line << std::endl;
            // Додаємо кількість символів у поточному рядку до загальної кількості символів у F2
            totalCharactersInF2 += line.length();
        }
    }
    // Закриваємо файли
    inputFile.close();
    outputFile.close();
    std::cout << "Amount F2: " << totalCharactersInF2 << std::endl;
    return 0;
}
