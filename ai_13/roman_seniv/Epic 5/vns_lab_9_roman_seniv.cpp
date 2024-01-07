#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    
    ofstream f1("F1.txt");
    if (!f1.is_open()) {
        cout << "Failed to open file F1.txt" << endl;
        return 1;
    }

    f1 << "Line 1: Hello world!" << endl;
    f1 << "Line 2: How are you?" << endl;
    f1 << "Line 3: This is a text file." << endl;
    f1 << "Line 4: Programming is interesting." << endl;
    f1 << "Line 5: Just another line." << endl;
    f1 << "Line 6: Another one." << endl;
    f1 << "Line 7: Some more information." << endl;
    f1 << "Line 8: Programming in C++." << endl;
    f1 << "Line 9: Learning about files." << endl;
    f1 << "Line 10: The last line." << endl;

    f1.close();

   
    ifstream f1Read("F1.txt");
    if (!f1Read.is_open()) {
        cout << "Failed to open file F1.txt for reading" << endl;
        return 1;
    }

    
    ofstream f2("F2.txt");
    if (!f2.is_open()) {
        cout << "Failed to open file F2.txt" << endl;
        return 1;
    }

    
    int K = 3; 
    string line;
    int currentLine = 0;

    while (getline(f1Read, line)) {
        currentLine++;
        if (currentLine >= K && currentLine < K + 5) {
            f2 << line << endl;
        }
    }

    f1Read.close();
    f2.close();

    
    ifstream f2Read("F2.txt");
    if (!f2Read.is_open()) {
        cout << "Failed to open file F2.txt for reading" << endl;
        return 1;
    }

    int vowelCount = 0;
    while (getline(f2Read, line)) {
        for (char ch : line) {
            if (tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' || tolower(ch) == 'o' || tolower(ch) == 'u') {
                vowelCount++;
            }
        }
    }

    f2Read.close();

    
    cout << "Number of vowels in file F2: " << vowelCount << endl;

    return 0;
}
