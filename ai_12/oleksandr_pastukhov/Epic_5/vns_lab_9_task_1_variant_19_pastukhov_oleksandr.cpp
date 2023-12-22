#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    using namespace std;

    ofstream f1("F1.txt");
    f1 << "apple orange banana" << endl;
    f1 << "apple peach kiwi" << endl;
    f1 << "grape mango pear" << endl;
    f1 << "cherry apple plum" << endl;
    f1 << "banana grape orange" << endl;
    f1 << "kiwi cherry mango" << endl;
    f1 << "pear peach apple" << endl;
    f1 << "plum mango kiwi" << endl;
    f1 << "orange banana cherry" << endl;
    f1 << "mango pear grape" << endl;
    f1.close();

    ifstream f1Read("F1.txt");
    
    ofstream f2("F2.txt");

    if(!f1Read.is_open() || !f2.is_open()) {
        cerr << "Unable to open the file." << endl;
        return 1;
    }

    string firstWord;
    getline(f1Read, firstWord); 

    string line;
    while(getline(f1Read, line)) {
        istringstream iss(line);
        string word;
        bool containsFirstWord = false;

        while(iss >> word) {
            if (word == firstWord) {
                containsFirstWord = true;
                break;
            }
        }

        if(!containsFirstWord) {
            f2 << line << endl;
        }
    }

    f1Read.close();
    f2.close();

    return 0;
}
