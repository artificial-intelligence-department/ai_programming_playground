#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int countConsonants(const string& str) {
    int count = 0;
    for (char ch : str) {
        if (isalpha(ch) && !isspace(ch) && strchr("aeiouAEIOU", ch) == nullptr) {
            count++;
        }
    }
    return count;
}

int main() {
    ifstream inputFile("F1.txt");
    ofstream outputFile("F2.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Помилка відкриття файлу." << endl;
        return 1;
    }

    int N1, N2;
    cout << "Введіть номер рядка N1: ";
    cin >> N1;
    cout << "Введіть номер рядка N2: ";
    cin >> N2;

    string line;
    int currentLineNumber = 0;

    while (getline(inputFile, line)) {
        currentLineNumber++;

        if (currentLineNumber >= N1 && currentLineNumber <= N2 && !line.empty() && line[0] == 'A') {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    ifstream outputFile2("F2.txt");

    if (!outputFile2.is_open()) {
        cerr << "Помилка відкриття файлу F2." << endl;
        return 1;
    }

    int maxConsonants = 0;
    int maxConsonantsLineNumber = 0;
    currentLineNumber = 0;

    while (getline(outputFile2, line)) {
        currentLineNumber++;
        int consonantCount = countConsonants(line);

        if (consonantCount > maxConsonants) {
            maxConsonants = consonantCount;
            maxConsonantsLineNumber = currentLineNumber;
        }
    }

    cout << "Номер рядка з найбільшою кількістю приголосних у файлі F2: " << maxConsonantsLineNumber << endl;

    outputFile2.close();

    return 0;
}