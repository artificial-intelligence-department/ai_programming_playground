#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string sortDigitsInWord(const string& word) {
    vector<int> digitsVector;

    for (char symbol : word) {
        if (isdigit(symbol)) {
            digitsVector.push_back(symbol - '0');
        }
    }

    sort(digitsVector.rbegin(), digitsVector.rend());

    string sortedWord = word;
    int index = 0;

    for (char& symbol : sortedWord) {
        if (isdigit(symbol)) {
            symbol = '0' + digitsVector[index];
            index++;
        }
    }
    return sortedWord;
}

string newString(const string& input) {

    stringstream stream(input);
    string word;
    string resultString;

    while (stream >> word) {
        resultString += sortDigitsInWord(word) + " ";
    }
    if (!resultString.empty()) {
        resultString.pop_back();
    }

    return resultString;
}

int main() {

    string words = "h2q8p0a qwe237rty s2unn56y";
    string newWords = newString(words);
    cout << "New string: " << newWords << endl;

    return 0;
}
