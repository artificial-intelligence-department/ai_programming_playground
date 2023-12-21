#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <sstream>

using namespace std;

void copyLinesToFile(const string& inputFile, const string& outputFile, int N1, int N2);
int countWordsInFirstLine(const string& filename);

int main() {
    int N1, N2;
    cout << "Enter N1 and N2: ";
    cin >> N1 >> N2;

    copyLinesToFile("F1.txt", "F2.txt", N1, N2);

    int wordCount = countWordsInFirstLine("F2.txt");
    if (wordCount >= 0) {
        cout << "Word count in the first line: " << wordCount << endl;
    }
    else {
        cerr << "Error counting words." << endl;
    }

    return 0;
}

void copyLinesToFile(const string& inputFile, const string& outputFile, int N1, int N2) {
    ifstream f1(inputFile);
    ofstream f2(outputFile);

    if (!f1.is_open() || !f2.is_open()) {
        cerr << "Error opening files." << endl;
        return;
    }

    string line;
    int currentLineNumber = 0;

    while (getline(f1, line)) {
        ++currentLineNumber;

        if (currentLineNumber >= N1 && currentLineNumber <= N2) {
            if (!line.empty() && line.front() == 'A' && line.back() == 'Z') {
                f2 << line << endl;
            }
        }

        if (currentLineNumber >= N2) {
            break;
        }
    }

    f1.close();
    f2.close();

    cout << "Copying completed successfully." << endl;
}

int countWordsInFirstLine(const string& inputFile) {
    ifstream f2(inputFile);

    if (!f2.is_open()) {
        cerr << "Error opening file." << endl;
        return -1;
    }

    string firstLine;
    getline(f2, firstLine);

    f2.close();

    istringstream iss(firstLine);
    int wordCount = distance(istream_iterator<string>(iss), istream_iterator<string>());

    return wordCount;
}
