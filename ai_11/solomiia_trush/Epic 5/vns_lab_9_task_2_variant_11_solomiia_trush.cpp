#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
    ofstream fileF1("F1.txt");
    if (!fileF1.is_open()) {
        cerr << "Unable to open " << endl;
        return 1;
    }


    fileF1 << "This is a sample text" << endl;
    fileF1 << "Hello, world!" << endl;
    fileF1 << "Shortest word" << endl;
    fileF1 << "Programming" << endl;
    fileF1 << "This file contains some text" << endl;
    fileF1 << "Clamor Spe" << endl;
    fileF1 << "Quick brown fox" << endl;
    fileF1 << "Slow old turtle" << endl;
    fileF1 << "Hide and seek" << endl;
    fileF1 << "End of the file" << endl;


    fileF1.close();


    ifstream fileF1Read("F1.txt");
    if (!fileF1Read.is_open()) {
        cerr << "Unable to open " << endl;
        return 1;
    }


    string line;
    string shortestWord;
    int shortestLine = 0;
    int currentLine = 0;


    while (getline(fileF1Read, line)) {
        currentLine++;


        istringstream iss(line);
        vector<string> words;
        string word;


        while (iss >> word) {
            words.push_back(word);
        }


        for (const auto& word : words) {
            if (shortestWord.empty() || word.length() < shortestWord.length()) {
                shortestWord = word;
                shortestLine = currentLine;
            }
        }
    }


    fileF1Read.close();


    fileF1Read.open("F1.txt");
    ofstream fileF2("F2.txt");
    if (!fileF1Read.is_open() || !fileF2.is_open()) {
        cerr << "Unable to open files for reading or writing." << endl;
        return 1;
    }


    currentLine = 0;


    while (getline(fileF1Read, line)) {
        currentLine++;
        if (currentLine != shortestLine) {
            fileF2 << line << endl;
        }
    }


    cout << "Line with the shortest word: " << shortestLine << endl;


    fileF1Read.close();
    fileF2.close();


    return 0;
    
}