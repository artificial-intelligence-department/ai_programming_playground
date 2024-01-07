#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int countConsonants(const string& line) {
    string consonants = "бвгджзйклмнпроооостфхцчшщ";
    int count = 0;

    for (char c : line) {
        if (isalpha(c) && islower(c) && consonants.find(c) != string::npos) {
            count++;
        }
    }

    return count;
}

int main() {

    ofstream f1("F1.txt");
    for (int i = 1; i <= 10; ++i) {
        f1 << "Рядок" << i << " для файлу F1\n";
    }
    f1.close();

    ifstream f1Read("F1.txt");
    ofstream f2("F2.txt");
    string firstWord;

    f1Read >> firstWord;

    f1Read.seekg(0);
    string line;

    while (getline(f1Read, line)) {
        if (line.find(firstWord) == string::npos) {
            f2 << line << "\n";
        }
    }

    f1Read.close();
    f2.close();


    ifstream f2Read("F2.txt");
    getline(f2Read, line);
    int consonantCount = countConsonants(line);

    cout << "Кількість приголосних букв у першому рядку F2: " << consonantCount << endl;

    f2Read.close();

    return 0;
}
