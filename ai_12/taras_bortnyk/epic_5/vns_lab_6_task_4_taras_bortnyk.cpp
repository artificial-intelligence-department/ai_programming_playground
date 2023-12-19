#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    const int maxSize = 255;
    char s1[maxSize];
    
    cout << "Input text: " << endl;
    gets(s1);

    stringstream ss(s1);
    string firstWord, word;

    ss >> firstWord; 

    cout << "Output text: " << endl;
    cout << s1 << endl;
    cout << "Length: " << strlen(s1) << endl;

    cout << "Words that match the first word:" << endl;
    cout << firstWord << " "; 

    while (ss >> word) {
        if (word == firstWord) {
            cout << word << " ";
        }
    }
    cout << endl;

    return 0;
}
