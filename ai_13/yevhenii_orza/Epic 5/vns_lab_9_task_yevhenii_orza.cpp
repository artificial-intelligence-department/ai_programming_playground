#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int countVowels(const string& str) {
    int count = 0;
    for (char c : str) {
        if (isVowel(c)) {
            count++;
        }
    }
    return count;
}

int main() {
    ifstream inputFile("F1.txt");
    ofstream outputFile("F2.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error: Unable to open file" << endl;
        return 1;
    }

    vector<string> lines;
    string line;
    while (getline(inputFile, line)) {
        lines.push_back(line);
    }

    int maxVowels = 0;
    int maxVowelsLine = 0;
    for (int i = 0; i < lines.size(); i++) {
        int vowels = countVowels(lines[i]);
        if (vowels > maxVowels) {
            maxVowels = vowels;
            maxVowelsLine = i;
        }
    }

    for (int i = 0; i < lines.size(); i++) {
        if (i != maxVowelsLine) {
            outputFile << lines[i] << endl;
        }
    }

    cout << "Line with most vowels: " << maxVowelsLine + 1 << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}