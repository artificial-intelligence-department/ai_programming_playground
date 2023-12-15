#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

const int sequenceLength = 10;
const float lowerBound = 1.0f;
const float upperBound = 10.0f;

void generateAndPrintSequence(ofstream& outputFile) {
    outputFile << "Послідовність: ";
    double sum = 0;

    for (int j = 0; j < sequenceLength; ++j) {
        float randomNumber = static_cast<float>(rand()) / RAND_MAX * (upperBound - lowerBound) + lowerBound; // Вимога №12: в коді використано перевантаження функції 
        outputFile << fixed << setprecision(2) << randomNumber << " ";
        sum += randomNumber;
    }

    double average = sum / sequenceLength;
    outputFile << "\nСереднє арифметичне: " << fixed << setprecision(2) << average << "\n\n";
}

// Вимога 15. в коді використано рекурсивну функцію 
void generateSequencesRecursively(ofstream& outputFile) {
    ifstream inputFile("input.txt"); // Вимога №20: в коді використано функції роботи з файлами, для того, щоб зчитати з файлу

    if (!inputFile) { //Вимога №5: в коді використані умовні оператори та розгалуження
        cerr << "Не вдалося відкрити файл input.txt." << endl;
        exit(1);
    }

    string userInput;

    inputFile >> userInput;

    if (userInput == "break") {
        inputFile.close();
        return;
    }

    generateAndPrintSequence(outputFile);
    generateSequencesRecursively(outputFile);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    ofstream outputFile("output.txt"); // Вимога №19: в коді використано функції роботи з файлами, для того, щоб записати у файл

    if (!outputFile) {
        cerr << "Не вдалося відкрити або створити файл output.txt." << endl;
        exit(1);
    }

    generateSequencesRecursively(outputFile);

    outputFile.close();
    return 0;
}
