#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

string findShortestWord(const string &line) {
    istringstream iss(line);
    string word, shortestWord = "";
    size_t shortestLength = numeric_limits<size_t>::max();

    while (iss >> word) {
        if (word.length() < shortestLength) {
            shortestLength = word.length();
            shortestWord = word;
        }
    }

    return shortestWord;
}

int main() {
    ofstream inputFile("F1.txt");
    if (!inputFile.is_open()) {
        cout << "Не вдалося створити або відкрити файл F1.txt." << endl;
        return 1;
    }

    cout << "Будь ласка, введіть текст для файлу F1.txt (для завершення введіть 'кінець'): " << endl;
    string inputText;
    while (getline(cin, inputText) && inputText != "кінець") {
        inputFile << inputText << endl;
    }
    inputFile.close();

    ifstream input("F1.txt");
    ofstream output("F2.txt");

    if (!input.is_open() || !output.is_open()) {
        cout << "Не вдалося відкрити файли." << endl;
        return 1;
    }

    string line;
    vector<string> lines;
    size_t lineNumber = 0, shortestLine = 0;
    size_t shortestWordLength = numeric_limits<size_t>::max();

    while (getline(input, line)) {
        lineNumber++;

        string shortestWord = findShortestWord(line);

        if (shortestWord.length() < shortestWordLength) {
            shortestWordLength = shortestWord.length();
            shortestLine = lineNumber;
        }

        lines.push_back(line);
    }

    input.close();

    if (shortestLine > 0 && shortestLine <= lines.size()) {
        lines.erase(lines.begin() + shortestLine - 1);
    }

    for (const auto &l : lines) {
        output << l << endl;
    }

    output.close();

    cout << "Рядок з найкоротшим словом: " << shortestLine << endl;

    return 0;
}