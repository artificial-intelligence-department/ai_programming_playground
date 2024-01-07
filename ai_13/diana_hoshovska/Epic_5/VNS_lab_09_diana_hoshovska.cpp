#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void copyLinesWithSingleWord(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open()) {
        cerr << "Failed to open file1." << endl;
        return;
    }
    if (!outputFile.is_open()) {
        cerr << "Failed to open file2." << endl;
        return;
    }
    
    string line;
    while (getline(inputFile, line)) { //програма зчитує файл (перший рядок в inputFile зберігає в line), допоки не дійде до eof
        istringstream iss(line);
        string word;
        if (!(iss >> word >> ws).eof()) { //якщо рядок з пропусками
            continue; //в рядку більше одного слова, пропустити його
        }
        outputFile << line << endl; //рядок містить тільки одне слово, скопіювати його в інший файл
    }
    cout << "Lines with one word are copied into " << outputFileName << endl;
}

string findLongestWord(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Failed to open file" << endl;
        return "";
    }

    string longestWord;
    string word;
    while (file >> word) {
        if (word.length() > longestWord.length()) {
            longestWord = word;
        }
    }
    return longestWord;
}

int main() {
    ofstream f1("F1.txt");
    if (f1.is_open()) {
        f1 << "Word\n";
        f1 << "Another word\n";
        f1 << "Many Words\n";
        f1 << "One\n";
        f1 << "BigWord\n";
        f1 << "So many\n";
        f1 << "Words\n";
        f1 << "ThisIsTheBiggestWord\n";
        f1 << "Wow\n";
        f1 << "Great\n";
        f1.close();
    } else {
        cerr << "Failed to open or create F1." << endl;
        return 1;
    }
    copyLinesWithSingleWord("F1.txt", "F2.txt");
    string longestWord = findLongestWord("F2.txt");
    if (!longestWord.empty()) {
        cout << "The longest word in F2: " << longestWord << endl;
    } else {
        cout << "F2 does not contain long words." << endl;
    }

    return 0;
}
