#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name);
FileOpResult copy_to_file(const char *fileName1, const char *fileName2);
int count_vowels(const string& line);

int main() {
    string fileName1;
    string fileName2;
    cout << "Enter name of the file you want to create and write to:\n";
    getline(cin, fileName1);
    cout << "Enter name of the file you want to copy lines without duplicates:\n";
    getline(cin, fileName2);
    FileOpResult resultOfWriting = write_to_file(fileName1.c_str());
    
   if (resultOfWriting == Success) {
        FileOpResult resultOfCopying = copy_to_file(fileName1.c_str(), fileName2.c_str());

        if (resultOfCopying == Success) {
            cout << "Success\n";
            ifstream FileNumber2(fileName2.c_str());
            string firstLine;
            if (getline(FileNumber2, firstLine, '.')) {
                
                int vowels = count_vowels(firstLine);
                cout << "Number of vowels in the first line in the second file: " << vowels << endl;
            }
            FileNumber2.close();
        } else {
            cout << "Failure\n";
        }
    } else {
        cout << "Failure\n";
    }
    return 0;
}

FileOpResult write_to_file(const char *name) {
    ofstream myFile(name);

    if (!myFile.is_open()) {
        return Failure;
    }

    
    for (int i = 0; i < 10; i++) {
        string text;
        cout << "Enter text for line " << i + 1 << ": ";
        getline(cin, text);
        myFile << text << endl;
    }

    myFile.close();
    return Success;
}
FileOpResult copy_to_file(const char *fileName1, const char *fileName2) {
    ifstream copyFromThisFile(fileName1);
    ofstream copyToThisFile(fileName2);

    if (!copyFromThisFile.is_open() || !copyToThisFile.is_open()) {
        return Failure;
    }

    string line;
    while (getline(copyFromThisFile, line)) {
        istringstream iss(line);

        unordered_set<string> wordsInLine; // Use a set to keep track of words seen within the same line
        bool duplicate = false;

        string word;
        while (iss >> word) {
            if (!wordsInLine.insert(word).second) {
                // If inserting the word into the set fails, it means the word is already present
                duplicate = true;
                break;
            }
        }

        if (!duplicate) {
            copyToThisFile << line << endl;
        }
    }

    copyFromThisFile.close();
    copyToThisFile.close();

    return Success;
}
int count_vowels(const string& line) {
    int vowelCount = 0;

    for (char c : line) {
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u'|| tolower(c)=='y') {
            vowelCount++;
        }
    }

    return vowelCount;
}


