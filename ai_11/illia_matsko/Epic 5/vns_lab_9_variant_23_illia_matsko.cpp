#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

void copyLinesWithSameWords(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error opening files." << endl;
        return;
    }

    string line;

    while (getline(inFile, line)) {
        istringstream iss(line);
        string word;
        map<string, int> wordCountMap;

        while (iss >> word) {
            wordCountMap[word]++;
        }

        for (const auto& entry : wordCountMap) {
            if (entry.second >= 2) {
                outFile << line << endl;
            }
        }
    }

    cout << "Words with count greater than two have been written to " << outputFile << endl;

    inFile.close();
    outFile.close();
}

int findWordWithMostA(const string& filename) {
    ifstream inFile(filename);

    if (!inFile.is_open()) {
        cerr << "Error opening file." << endl;
        return -1;
    }

    int maxACount = 0;
    int wordNumber = 0;
    string line;
    int currentWordNumber = 1;

    while (getline(inFile, line)) {
        istringstream iss(line);
        string word;


        while (iss >> word) {
            int aCount = count(word.begin(), word.end(), 'a');

            if (aCount > maxACount) {
                maxACount = aCount;
                wordNumber = currentWordNumber;
            }

            currentWordNumber++;
        }
    }

    inFile.close();

    if (maxACount > 0) {
        cout << "The word with the most 'a's is at position: " << wordNumber << endl;
    } else {
        cout << "No word with 'a' found." << endl;
    }

    return wordNumber;
}

void displayFileContent(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        cout << "Content of " << filename << ":\n";
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Error opening file " << filename << endl;
    }
}

int main() {
    ofstream f1("F1.txt");
    if (f1.is_open()) {
        f1 << "sdhjkgfkldsf dfv jdfj jdgfh" << endl;
        f1 << "aaaaaaaa kjdfgk jdhfksg jfhdjdf" << endl;
        f1 << "njhjhf njhjhf sdf" << endl;
        f1.close();
    } else {
        cerr << "Error opening file F1.txt for writing." << endl;
        return 1;
    }

    copyLinesWithSameWords("F1.txt", "F2.txt");

    findWordWithMostA("F1.txt");

    cout << endl;

    displayFileContent("F2.txt");

    return 0;
}