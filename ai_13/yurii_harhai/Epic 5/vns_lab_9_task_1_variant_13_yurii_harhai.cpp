#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;
void createF1();
void copyLines(int N1, int N2);
int findMaxConsonants();
void printF2();

int main() {
    createF1();
    copyLines(0, 9);
    printF2();
    int lineNumber = findMaxConsonants();

    cout << "Most consonants: " << lineNumber << endl;

    return 0;
}


// Створення файлу F1 з 10 рядками інформації
void createF1() {
    ofstream F1("F1.txt");

    for (int i = 0; i < 10; i++) {
        string line;
        cout << "Enter row number " << i + 1 << ": ";
        getline(cin, line);
        F1 << line << endl;
    }

    F1.close();
}

// Копіювання рядків з F1 в F2
void copyLines(int N1, int N2) {
    ifstream F1("F1.txt");
    ofstream F2("F2.txt");

    vector<string> lines;
    string line;

    while (getline(F1, line)) {
        lines.push_back(line);
    }

    for (int i = N1; i <= N2; i++) {
        if (lines[i][0] == 'A') {
            F2 << lines[i] << endl;
        }
    }

    F1.close();
    F2.close();
}

// Визначення номера рядка з найбільшою кількістю приголосних букв у файлі F2
int findMaxConsonants() {
    ifstream F2("F2.txt");

    string vowels = "aeiouAEIOU";
    vector<string> lines;
    string line;
    int maxConsonants = 0;
    int lineNumber = 0;

    while (getline(F2, line)) {
        lines.push_back(line);
    }

    for (int i = 0; i < lines.size(); i++) {
        int consonants = 0;
        for (char c : lines[i]) {
            if (isalpha(c) && vowels.find(c) == string::npos) {
                consonants++;
            }
        }
        if (consonants > maxConsonants) {
            maxConsonants = consonants;
            lineNumber = i+1;
        }
    }

    F2.close();

    return lineNumber;
}

// Друкування вмісту файлу F2
void printF2() {
    ifstream F2("F2.txt");
    string line;

    while (getline(F2, line)) {
        cout << line << endl;
    }

    F2.close();
}
