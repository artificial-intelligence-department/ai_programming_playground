#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    ofstream fileF1("F1.txt");
    if (!fileF1.is_open()) {
        cout << "Error creating F1.txt" << endl;
        return 1;
    }

    fileF1 << "Dota 2 is a 2013 multiplayer online battle arena" << endl;
    fileF1 << "The game is a sequel to Defense of the Ancients" << endl;
    fileF1 << "Dota 2 is played in matches between two teams of five players" << endl;
    fileF1 << "with each team occupying and defending their own separate base on the map" << endl;
    fileF1 << "Each of the ten players independently " << endl;
    fileF1 << "controls a powerful character known as a hero" << endl;
    fileF1 << "that all have unique abilities and differing styles of play" << endl;
    fileF1 << "During a match players collect experience points and items for their heroes" << endl;
    fileF1 << "meow" << endl;
    fileF1 << "oksana the best" << endl;

    fileF1.close();

    ifstream fileF1Read("F1.txt");
    if (!fileF1Read.is_open()) {
        cout << "Error opening F1.txt for reading" << endl;
        return 1;
    }

    ofstream fileF2("F2.txt");
    if (!fileF2.is_open()) {
        cout << "Error creating F2.txt" << endl;
        return 1;
    }

    int N1;
    cin>>N1; 
    int N2;
    cin>>N2; 

    string line;
    int maxVowelsLine = 0;
    int maxVowelsCount = 0;

    for (int i = 1; getline(fileF1Read, line); ++i) {
        if (i >= N1 && i <= N2) {
            if (line.find('A') == string::npos) { // No elements found
                fileF2 << line << endl; 

                int vowelsCount = count_if(line.begin(), line.end(), isVowel);
                if (vowelsCount > maxVowelsCount) {
                    maxVowelsCount = vowelsCount;
                    maxVowelsLine = i;
                }
            }
        }
    }

    cout << "Line number with the most vowels in F2: " << maxVowelsLine << endl;

    fileF1Read.close();
    fileF2.close();

    return 0;
}
