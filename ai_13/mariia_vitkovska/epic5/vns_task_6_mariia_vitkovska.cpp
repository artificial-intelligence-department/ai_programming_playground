#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

int CountWords(const string& str) {
    istringstream stream(str);
    string word;
    int wordCount = 0;

     while (stream >> word) {
        wordCount++;
    }

    return wordCount;
}


int main() {
    string input;

    cout << "Enter a line: ";
    getline(cin, input);

    int NumberOfWords = CountWords(input);

    cout << "Number of words in the entered line: " << NumberOfWords << endl;
}
