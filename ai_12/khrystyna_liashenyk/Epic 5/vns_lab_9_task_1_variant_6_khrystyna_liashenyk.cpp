#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool isConsonant(char c) {
    c = tolower(c);
    return (c >= 'a' && c <= 'z' && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

void copyLinesFromF1ToF2(const string& file1, const string& file2, int startLine, int endLine) {
    ifstream inputFile(file1);
    ofstream outputFile(file2);

    if (!inputFile || !outputFile) {
        cerr << "Unable to open files!" << endl;
        return;
    }

    string line;
    int currentLine = 1;

    while (getline(inputFile, line)) {
        if (currentLine >= startLine && currentLine <= endLine) {
            outputFile << line << endl;
        }
        if (currentLine == endLine) {
            break;
        }
        ++currentLine;
    }

    inputFile.close();
    outputFile.close();
}

int countConsonants(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Unable to open file!" << endl;
        return -1;
    }

    int consonantCount = 0;
    char c;

    while (file.get(c)) {
        if (isConsonant(c)) {
            consonantCount++;
        }
    }

    file.close();
    return consonantCount;
}

int main() {
    string file1 = "F1.txt";
    string file2 = "F2.txt";
    int startLine, endLine;

    cout << "Enter the starting line: ";
    cin >> startLine;
    cout << "Enter the ending line: ";
    cin >> endLine;

    copyLinesFromF1ToF2(file1, file2, startLine, endLine);
    cout << "Lines copied from F1 to F2 from line " << startLine << " to line " << endLine << endl;

    int consonantCount = countConsonants(file2);
    if (consonantCount != -1) {
        cout << "Number of consonants in file F2: " << consonantCount << endl;
    }

    return 0;
}
