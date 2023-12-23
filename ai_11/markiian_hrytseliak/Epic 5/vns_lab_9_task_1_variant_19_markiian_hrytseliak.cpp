#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int countConsonants(const string& str) {
    int consonantCount = 0;
    for (char c : str) {
        if (isalpha(c) && !isVowel(c)) {
            consonantCount++;
        }
    }
    return consonantCount;
}

void createAndWriteToFile(const string& filename, int lines) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file " << filename << " for writing!" << endl;
        return;
    }

    for (int i = 0; i < lines; ++i) {
        string line;
        cout << "Enter line " << (i + 1) << ": ";
        getline(cin, line);
        file << line << endl;
    }

    file.close();
}

void copyLinesWithoutMatchingWord(const string& inputFilename, const string& outputFilename) {
    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        cerr << "Error opening file " << inputFilename << " for reading!" << endl;
        return;
    }

    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        cerr << "Error opening file " << outputFilename << " for writing!" << endl;
        inputFile.close();
        return;
    }

    string wordToMatch;
    cout << "Enter word to match: ";
    cin >> wordToMatch;

    string line;
    while (getline(inputFile, line)) {
        // Check if the line doesn't contain the specified word
        if (line.find(wordToMatch) == string::npos) {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();
}

int main() {

    string filename1 = "File1.txt";
    string filename2 = "File2.txt";
    const string path = "C:/Users/Gil/OneDrive/Documents/GitHub/desktop-tutorial/Programming/Code/Epic 5/";
    string file1 = path+filename1;
    string file2 = path+filename2;
    const int numLines = 10;

    // Task 1: Create File1 and write 10 lines
    createAndWriteToFile(file1, numLines);

    // Task 2: Copy lines from File1 to File2 without matching word
    copyLinesWithoutMatchingWord(file1, file2);

    // Task 3: Count consonants in the first line of File2
    ifstream file2Stream(file2);
    if (!file2Stream.is_open()) {
        cerr << "Error opening file " << file2 << " for reading!" << endl;
        return 1;
    }

    string firstLine;
    getline(file2Stream, firstLine);

    int consonantCount = countConsonants(firstLine);

    cout << "Number of consonants in the first line of " << filename2 << ": " << consonantCount << endl;

    file2Stream.close();

    return 0;
}