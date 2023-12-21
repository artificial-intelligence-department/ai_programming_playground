#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string cleanWord(const string &word) {
    string cleaned;
    for (char c : word) {
        if (isalnum(c)) {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}

bool isUniqueLine(const string &line) {
    istringstream iss(line);
    vector<string> lineWords;
    string word;

    while (iss >> word) {
        lineWords.push_back(cleanWord(word));
    }

    return all_of(lineWords.begin(), lineWords.end(), [lineWords](const string &w) {
        return count(lineWords.begin(), lineWords.end(), w) == 1;
    });
}

int countVowels(const string &str) {
    int vowels = 0;
    for (char c : str) {
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u' || tolower(c) == 'y') {
            vowels++;
        }
    }
    return vowels;
}

int main() {
    string text[] = {
        "Cats purr when they're content.\n",
        "Sunflowers turn towards the sun.\n",
        "Raindrops glistened on the window pane.\n",
        "Laughter echoed through the empty hallways.\n",
        "The moonlit night was calm and serene.\n"};

    ofstream fout1("F1.txt");
    if (!fout1) {
        cerr << "Error occurred" << endl;
        return 1;
    }

    for (const string &str : text) {
        fout1 << str;
    }

    fout1.close();

    ifstream fin1("F1.txt");
    ofstream fout2("F2.txt");
    if (!fin1 || !fout2) {
        cerr << "Error occurred" << endl;
        return 1;
    }

    string line;
    while (getline(fin1, line)) {
        if (isUniqueLine(line)) {
            fout2 << line << endl;
        }
    }

    fout2.close();
    fin1.close();

    ifstream fin2("F2.txt");
    if (!fin2) {
        cerr << "Error occurred" << endl;
        return 1;
    }

    string firstLine;
    getline(fin2, firstLine);
    int vowels = countVowels(firstLine);

    fin2.close();

    cout << "There are " << vowels << " vowels in the first line\n";

    return 0;
}









