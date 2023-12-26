#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int countConsonants(const string& word) {
    int count = 0;
    for (char c : word) {
        if (isalpha(c) && !strchr("aeiouAEIOU", c)) {
            count++;
        }
    }
    return count;
}

int main() {
    ofstream outputFile("output.file.txt");

    outputFile << "Hello\n";
    outputFile << "Today is Monday\n";
    outputFile << "I want to sleep\n";
    outputFile << "Eat\n";
    outputFile << "Repeat\n";
    outputFile << "My cat is hungry\n";
    outputFile << "Cool\n";
    outputFile << "Playground\n";

    outputFile.close();
    ifstream inputFile("output.file.txt");
    ofstream resultFile("result.file.txt");
    string line;
    int currentWordNumber = 0;
    int maxConsonantCount = 0;
    int wordNumberWithMaxConsonants = 0;

    while (getline(inputFile, line)) {
        cout << "Line: " << line << "\n";

        bool singleWord = true;
        for (char w : line) {
            if (w == ' ') {
                singleWord = false;
                break;
            }
        }

        if (singleWord) {
            currentWordNumber++;
            int consonantCount = countConsonants(line);

            if (consonantCount > maxConsonantCount) {
                maxConsonantCount = consonantCount;
                wordNumberWithMaxConsonants = currentWordNumber;
            }

            resultFile << line << "\n";
        }
    }

    inputFile.close();
    resultFile.close();

    cout << "\n";
    ifstream resultInput("result.file.txt");

    while (getline(resultInput, line)) {
        cout << line << "\n";
    }

    resultInput.close();

    cout << "\n";
    cout << "The word number with the most consonants: " << wordNumberWithMaxConsonants << "\n";

    return 0;
}