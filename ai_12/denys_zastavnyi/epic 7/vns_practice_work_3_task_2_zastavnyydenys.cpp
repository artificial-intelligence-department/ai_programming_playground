#include <iostream>
#include <fstream>

using namespace std;

// Функція для розрахунку кількості російських слів та довжини відрізка
void calculateMetrics(int totalPages, int wordsPerPage, int averageWordLength, int letterWidth) {
    int totalRussianWords = 0; //1. в коді використана як мінімум одна цілочисельна змінна

    int totalWidth = 0;

    for (int page = 1; page <= totalPages; ++page) { //10. в коді використаний for цикл
        totalRussianWords += wordsPerPage;

        for (int word = 1; word <= wordsPerPage; ++word) {
            totalWidth += averageWordLength * letterWidth;
        }
    }

    // Виведення результатів
    cout << "The number of Russian words in the dictionary: " << totalRussianWords << endl;
    cout << "Segment length: " << totalWidth << " mm" << endl;
}

int main() {
    ifstream inputFile("input.txt"); // Відкриття файлу для зчитування

    if (inputFile.is_open()) {
        int totalPages, wordsPerPage, averageWordLength, letterWidth;

        //17. в коді використано функції роботи з файлами, для того, щоб зчитати з файлу
        inputFile >> totalPages >> wordsPerPage >> averageWordLength >> letterWidth;

      //14. в коді використано параметри та аргументи функції
        calculateMetrics(totalPages, wordsPerPage, averageWordLength, letterWidth);

        inputFile.close(); // Закриття файлу
    } else {
        cout << "Error opening file for reading." << endl;
    }

    return 0;
}
