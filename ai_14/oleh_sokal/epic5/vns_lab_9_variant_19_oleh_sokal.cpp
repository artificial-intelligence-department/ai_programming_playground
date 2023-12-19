#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;




bool vowel(char ch);


int main() {
    char firstWord[255];




    ofstream f1("F1.txt");




    if (!f1.is_open()) {
        cout << "Failed to open file F1.txt." << endl;
        return 1;
    }




    for (int i = 0; i < 10; i++) {
        cout << "Enter " << i + 1 << " lines for F1.txt:" << endl;
        string line;
        getline(cin, line);
        f1 << line << endl;
    }


    f1.close();




    ifstream f1R("F1.txt");
    ofstream f2("F2.txt");




    if (!f1R.is_open() || !f2.is_open()) {
        cout << "Failed to open files." << endl;
        return 1;
    }




    f1R >> firstWord;


 
    f1R.clear();
    f1R.seekg(0, ios::beg);




    string line;  
    int consonantCount = 0;




    if (getline(f1R, line)) {
        for (char ch : line) {
            if (!vowel(ch) && ch != ' ') {
                consonantCount++;
            }
        }
        cout << "Number of consonants in the first line of F2: " << consonantCount << endl;
        f2 << line << endl;  
    }




    while (getline(f1R, line)) {
        bool choice = true;




        stringstream ss(line);
        string word;




        while (ss >> word) {
            if (word == firstWord) {
                choice = false;
                break;
            }
        }


 
        if (choice) {
            f2 << line << endl;
        }
    }


    f1R.close();
    f2.close();


 
    cout << "Program executed successfully. Press Enter to exit.";
    cin.get();


    return 0;
}




bool vowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
