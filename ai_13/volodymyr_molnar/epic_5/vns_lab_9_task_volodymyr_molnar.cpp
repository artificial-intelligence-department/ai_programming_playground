#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

bool isPrigolosna(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void copyLines(const string& inputFile, const string& outputFile, int N, int K) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (inFile.is_open() && outFile.is_open()) {
        string line;
        int currentLine = 1;

        while (currentLine < N && getline(inFile, line)) 
            currentLine++;

        while (currentLine <= K && getline(inFile, line)) {
            outFile << line << endl;
            currentLine++;
        }

        inFile.close();
        outFile.close();
    }
    else 
        cout << "error" << endl;

}

int countPrigolosnih(const string& filename) {
    ifstream file(filename);
    int consonantCount = 0;

    if (file.is_open()) {
        string line;
        while (getline(file, line)) 
            for (char c : line) 
                if (isalpha(c) && !isPrigolosna(c)) 
                    consonantCount++;
        file.close();
    }
    else 
        cout << "Не вдалося відкрити файл." << endl;

    return consonantCount;
}

int main() {
    string inputFilename, outputFilename;
    cout << "enter input name of file: ";
    cin >> inputFilename;
    cout << "enter output name of file: ";
    cin >> outputFilename;

    int N, K;
    cout << "enter N: ";
    cin >> N;
    cout << "enter K: ";
    cin >> K;

    copyLines(inputFilename, outputFilename, N, K);

    int prigolosniCount = countPrigolosnih(outputFilename);

    cout << "count of Prigolosni letter in file " << outputFilename << ": " << prigolosniCount << endl;

    return 0;
}
