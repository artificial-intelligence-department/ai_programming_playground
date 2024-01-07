#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ofstream F1("F1.txt");
    if (!F1.is_open()) {
        cerr << "An error occurred while attempting to open the file" << endl;
        return 1;
    }

    vector<string> str(10);
    for (int a=0; a<10; ++a) {
        cout << "Enter a string: ";
        getline(cin, str[a]);
        F1 << str[a] << endl;
        cin.ignore();
    }

    F1.close();

    int N=0;
    int K=0;
    do{
        cout << "Enter the number of the line starting from which copying to another file will take place: ";
        cin >> N;
    } while (N <= 0 || N >= 10);

    do{
        cout << "Enter the line number that will end copying to another file: ";
        cin >> K;
    } while (K <= 0 || K >= 10);

    ifstream F1read("F1.txt");
    ofstream F2("F2.txt");

    if (!F1read.is_open() || !F2.is_open()) {
        cerr << "An error occurred while attempting to open file F1 or F2" << endl;
        return 1;
    }

    string line;
    int a=1;
    for(int a=1; a<=K || a >= N && getline(F1read, line); ++a) {
        F2 << "\n" << line << endl;  
    } 

    F1read.close();
    F2.close();

    ifstream F2read("F2.txt");
    if (!F2read.is_open()) {
        cerr << "An error occurred while attempting to open the file" << endl;
        return 1;
    }

    int consonant;
    char symbol;

    while(F2read.get(symbol)) {
        if (isalpha(symbol) && (symbol != 'a' || symbol != 'A' || symbol != 'e' || symbol != 'E' || symbol != 'i' || symbol != 'I' || symbol != 'o' || symbol != 'O' || symbol != 'u' || symbol != 'U' || symbol != 'y' || symbol != 'Y')) {
            ++consonant;
        } 
    }

    F2read.close();

    cout << "The amount of consonants in F2.txt: " << consonant << endl;

    return 0;
}