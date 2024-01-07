#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>
#define n 255
using namespace std;
bool isDigit(char c);

int main() {
    char text[n];
    cout << "Enter text:\n";
    cin.getline(text, n);

    
    istringstream iss(text);
    string word;
    vector<string> wordsWithNumber;
        while (iss >> word) {
        if (isDigit(word[0])) {
            wordsWithNumber.push_back(word);
        }
    }

    if (wordsWithNumber.empty()) {
        cout << "There are no words that start with a digit.\n";
    } else {
    sort(wordsWithNumber.rbegin(), wordsWithNumber.rend());

    cout << "Words that start with a digit (in descending order):\n";
    for (string &element : wordsWithNumber) {
        cout << element << endl;
    }}

    return 0;
}

bool isDigit(char c) {
    if (c >= '0' && c <= '9'){
    return true;}
    else{ return false;}
}


