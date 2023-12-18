#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int countLastWordCharacters(const string& line) {
    int length = line.length();
    int lastWordLength = 0;
    bool foundLastWord = false;

    for (int i = length - 1; i >= 0; --i) {
        if (line[i] != ' ' && !foundLastWord) {
            foundLastWord = true;
            lastWordLength++;
        } else if (line[i] != ' ' && foundLastWord) {
            lastWordLength++;
        } else if (line[i] == ' ' && foundLastWord) {
            break;
        }
    }

    return lastWordLength;
}

int main() {
    ofstream fileF1("F1.txt");

    cout << "Enter 10 lines of text for file F1:" << endl;

    
    for (int i = 0; i < 10; ++i) {
        string inputLine;
        cout << "Enter line " << (i + 1) << ": ";
        getline(cin, inputLine);
        fileF1 << inputLine << endl;
    }

    fileF1.close();

    ifstream fileF1Read("F1.txt"); 
    ofstream fileF2("F2.txt"); 

    string line;
    int lineCount = 0;

    
    while (getline(fileF1Read, line)) {
        lineCount++;
        if (lineCount >= 4) {
            fileF2 << line << endl;
        }
    }

    fileF1Read.close();
    fileF2.close(); 

    ifstream fileF2Read("F2.txt"); 

    
    string lastLine;
    while (getline(fileF2Read, line)) {
        lastLine = line;
    }

    int lastWordLength = countLastWordCharacters(lastLine);
    cout << "Number of characters in the last word in file F2: " << lastWordLength << endl;

    fileF2Read.close(); 
    return 0;
}
