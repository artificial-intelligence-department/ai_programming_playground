#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

void copyLinesBetween(const string& inputPath, const string& outputPath, int startLine, int endLine) {
    ifstream inputFile(inputPath);
    ofstream outputFile(outputPath);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Failed to open files." << endl;
        return;
    }

    string line;
    int currentLine = 0;

    while (getline(inputFile, line)) {
        ++currentLine;
        if (currentLine >= startLine && currentLine <= endLine && !line.empty() && line[0] == 'A') {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();
}

int findLineWithMostConsonants(const string& filePath) {
    ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        cerr << "Failed to open the file." << endl;
        return -1;
    }

    int maxConsonantsCount = 0;
    int maxConsonantsLine = 0;

    string line;
    int currentLine = 0;

    while (getline(inputFile, line)) {
        ++currentLine;
        int consonantsCount = 0;

        for (char c : line) {
            if (isalpha(c) && tolower(c) != 'a' && tolower(c) != 'e' &&
                tolower(c) != 'i' && tolower(c) != 'o' && tolower(c) != 'u' &&
                tolower(c) != 'y' && isalnum(c)) {
                ++consonantsCount;
            }
        }

        if (consonantsCount > maxConsonantsCount) {
            maxConsonantsCount = consonantsCount;
            maxConsonantsLine = currentLine;
        }
    }

    inputFile.close();
    return maxConsonantsLine;
}

int main() {
    const string fileF1Path = "F1.txt";
    const string fileF2Path = "F2.txt";
    const int N1 = 3;
    const int N2 = 8;

    copyLinesBetween(fileF1Path, fileF2Path, N1, N2);
    int resultLineNumber = findLineWithMostConsonants(fileF2Path);

    cout << "Task 1: Successfully copied lines starting with 'A' from lines " << N1
              << " to " << N2 << " to file " << fileF2Path << "." << endl;

    if (resultLineNumber != -1) {
        cout << "Task 2: Line number with the most consonants in file " << fileF2Path
                  << ": " << resultLineNumber << "." << endl;
    } else {
        cerr << "Task 2: Failed to find the line with the most consonants." << endl;
    }

    return 0;
}