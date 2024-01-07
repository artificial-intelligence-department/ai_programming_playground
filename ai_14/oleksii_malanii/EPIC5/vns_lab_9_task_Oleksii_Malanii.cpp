#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    ifstream inputFile("F1.txt");
    if (!inputFile.is_open()) {
        cout << "Failed to open file F1." << endl;
         return 1;
    }
    ofstream outputFile("F2.txt");
    if (!outputFile.is_open()) {
        cout << "Failed to open file F2 for writing." << endl;
            return 1;
    }
    int K = 3; 
    string line;
    for (int i = 0; i < K + 6; ++i) {
        getline(inputFile, line);
        if (i >= K) {
            outputFile << line << endl;
        }
    }
    inputFile.close();
    outputFile.close();
    ifstream countFile("F2.txt");
    if (!countFile.is_open()) {
        cout << "Failed to open file F2 for counting vowels." << endl;
            return 1;
    }
    int vowelCount = 0;
    while (getline(countFile, line)) {
        for (char c : line) {
            if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {
                vowelCount++;
            }
        }
    }
    cout << "Number of vowels in file F2: " << vowelCount << endl;
    countFile.close();
    return 0;
}
