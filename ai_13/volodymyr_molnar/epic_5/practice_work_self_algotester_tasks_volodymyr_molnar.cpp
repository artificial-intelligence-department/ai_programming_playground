#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    cout << "enter text: ";
    string userText;
    getline(cin, userText);

    ofstream outFile("example.txt");

    if (!outFile.is_open()) {
        cerr << "can`t open the file." << endl;
        return 1; //return error
    }

    outFile << userText << endl;

    outFile.close();

    ifstream inFile("example.txt");

    if (!inFile.is_open()) {
        cerr << "can`t open the file for reading." << endl;
        return 1; 
    }

    cout << "file:" << endl;
    string line;
    while (getline(inFile, line)) 
        cout << line << endl;


    inFile.close();

    return 0; 
}
