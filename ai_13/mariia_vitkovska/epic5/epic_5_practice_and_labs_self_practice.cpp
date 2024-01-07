#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    string firstFileName = "characters.txt";
    string secondFileName = "favorite_character.txt";


    ifstream firstFile(firstFileName);

    if (!firstFile.is_open()) {
        cerr << "File " << firstFileName << " not found. Creating the file." << endl;
        ofstream createFirstFile(firstFileName);

        if (!createFirstFile.is_open()) {
            cerr << "Failed to create " << firstFileName << endl;
            return 1;
        }

        createFirstFile << "Harry Potter\nBatman\nLorax\nWalter White\nHeo\n";
        createFirstFile.close();

        firstFile.open(firstFileName);
    }

    cout << "Which character do u like the most of all available?" << endl;
    cout << "Available characters:" << endl;
    string character;
    while (getline(firstFile, character)) {
        cout << character << endl;
    }

    cout << "Choose your favorite character: ";
    getline(cin, character);


    ofstream secondFile(secondFileName, ios::app);
    if (!secondFile.is_open()) {
        cerr << "Failed to open " << secondFileName << " for writing." << endl;
        return 1;
    }

    secondFile << character << endl;
    
    firstFile.close();
    secondFile.close();

    cout << "Your favorite character has been added to " << secondFileName << endl;

    return 0;
}
