#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int countVowels(const std::string& str) {
    int vowelCount = 0;
    for (char ch : str) {
        // Перевіряємо, чи символ є голосним
        if (std::isalpha(ch) && (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                                 ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')) {
            vowelCount++;
        }
    }
    return vowelCount;
}
void createFirstFile(std::string str){
    std::ofstream outputFile("F1.txt", std::ios::trunc);
     if (outputFile.is_open()) {
        outputFile << "Bright stars hung in the dark sky, resembling diamonds on a black velvet blanket.\n";
        outputFile << "The aroma of freshly brewed coffee pierces the morning mist, filling the kitchen with warmth and comfort.\n";
        outputFile << "The laughter of children echoes in the backyard, spreading joy and merriment.\n";
        outputFile << "The babbling brook softly whispers among the rocks, creating a natural symphony of forest life.\n";
        outputFile << "The vibrant colors of spring flowers blossom in the park, awakening nature from its winter slumber.\n";
        outputFile << "The sun sets on the horizon, painting the sky in shades of pink and orange.\n";
        outputFile << "A gentle breeze embraces the face, carrying the scent of the sea and distant adventures.\n";
        outputFile << "Ancient streets in the city center glisten with reflections from evening lanterns.\n";
        outputFile << "The soft purple light of street café lanterns creates an atmosphere of warmth and romance.\n";
        outputFile << "Fresh fruits sit on the table in the room, enticing appetite and promising a flavorful day.\n";
        // Закрити файл
        outputFile.close();
}
}

int main() {
    std::string name = "F1.txt";
    createFirstFile(name);
    std::ifstream inputFile("F1.txt"); // Відкриваємо вхідний файл для читання
    std::ofstream outputFile("F2.txt",std::ios::out | std::ios::trunc); // Відкриваємо вихідний файл для запису

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error!" << std::endl;
        return 1;
    }

    std::string line;
    int lineCount = 0;
    int maxVowelCount = 0;
    int lineWithMaxVowels = 0;

    // Читаємо рядки з файлу та знаходимо рядок з найбільше голосними
    while (std::getline(inputFile, line)) {
        lineCount++;
        int currentVowelCount = countVowels(line);

        // Порівнюємо з поточним найбільшим числом голосних символів
        if (currentVowelCount > maxVowelCount) {
            maxVowelCount = currentVowelCount;
            lineWithMaxVowels = lineCount;
        }
    }

    // Повторно відкриваємо вхідний файл для повторного читання
    inputFile.clear();
    inputFile.seekg(0);

    // Читаємо рядки з файлу та записуємо їх у вихідний файл, крім рядка з найбільше голосними
    lineCount = 0;
    while (std::getline(inputFile, line)) {
        lineCount++;
        if (lineCount != lineWithMaxVowels) {
            outputFile << line << std::endl;
        }
      
        
    }

    // Закриваємо файли
    inputFile.close();
    outputFile.close();

    std::cout << "Видалено рядок № " << lineWithMaxVowels
              << " з " << maxVowelCount << " голосними буквами." << std::endl;

    return 0;
}
