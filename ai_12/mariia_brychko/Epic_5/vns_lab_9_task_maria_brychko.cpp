#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Функція для перевірки, чи рядок містить тільки одне слово
bool containsSingleWord(const string &line) {
    istringstream iss(line);
    string word;
    int wordCount = 0;
    while (iss >> word) {
        wordCount++;
    }
    return wordCount == 1;
}

// Функція для пошуку найдовшого слова у векторі слів
string findLongestWord(const vector<string>& lines) {
    string longestWord;
    for (const string& line : lines) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            if (word.length() > longestWord.length()) {
                longestWord = word;
            }
        }
    }
    return longestWord;
}

int main() {
    // Очищення файлів F1.txt і F2.txt перед початком роботи програми
    ofstream clearFile1("F1.txt", ofstream::out | ofstream::trunc);
    ofstream clearFile2("F2.txt", ofstream::out | ofstream::trunc);
    clearFile1.close();
    clearFile2.close();

    // Введення слів у файл F1.txt
    ofstream input_File("F1.txt", ios::app);
    if (!input_File.is_open()) {
        cerr << "Error: Could not create or open file 'F1.txt'." << endl;
        return 1;
    }

    cout << "Enter words to add to file 'F1.txt' (type 'exit' to finish):\n";

    string word;
    while (true) {
        getline(cin, word);

        if (word == "exit") {
            break;
        }

        input_File << word << endl;
    }

    input_File.close();

    // Отримання рядків з файлу F1.txt
    ifstream inputFile("F1.txt");
    if (!inputFile.is_open()) {
        cerr << "Failed to open file F1.txt\n";
        return 1;
    }

    vector<string> allLines;
    string line;

    while (getline(inputFile, line)) {
        allLines.push_back(line);
    }

    inputFile.close();

    // Запис рядків з одним словом у файл F2.txt та знаходження найдовшого слова
    ofstream outputFile("F2.txt");
    if (!outputFile.is_open()) {
        cerr << "Failed to create file F2.txt\n";
        return 1;
    }

    string longestWord = findLongestWord(allLines);
    if (longestWord.empty()) {
        cout << "The file does not contain any words\n";
    } else {
        cout << "Longest word in file: " << longestWord << '\n';
    }

    cout << "Lines containing single words from 'F1.txt':\n";
    for (const string& line : allLines) {
        if (containsSingleWord(line)) {
            cout << line << '\n';
            outputFile << line << '\n';
        }
    }

    outputFile << "Longest word in file: " << longestWord << '\n';
    outputFile.close();

    return 0;
}
