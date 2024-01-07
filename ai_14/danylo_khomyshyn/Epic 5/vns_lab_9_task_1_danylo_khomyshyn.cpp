#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void copyLinesStartingWithA(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Помилка відкриття файлу для читання або запису!" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        if (!line.empty() && line[0] == 'А') {
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();
}

int countWordsInFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу для читання!" << endl;
        return -1;
    }

    string word;
    int wordCount = 0;

    while (file >> word) {
        wordCount++;
    }

    file.close();
    return wordCount;
}

int main() {
    ofstream f1("F1.txt");
    if (!f1.is_open()) {
        cerr << "Помилка відкриття файлу F1 для запису!" << endl;
        return 1;
    }

    f1 << "Італія\n";
    f1 << "Японія\n";
    f1 << "Аргентина\n";
    f1 << "Україна\n";
    f1 << "Австралія\n";
    f1 << "Індія\n";
    f1 << "Швеція\n";
    f1 << "Бразилія\n";
    f1 << "США\n";
    f1 << "Греція\n";

    f1.close();

    copyLinesStartingWithA("F1.txt", "F2.txt");

    cout << "Вміст файлу F2:" << endl;
    ifstream f2("F2.txt");
    if (f2.is_open()) {
        string line;
        while (getline(f2, line)) {
            cout << line << endl;
        }
        f2.close();
    } else {
        cerr << "Помилка відкриття файлу F2 для читання!" << endl;
        return 1;
    }

    int wordCount = countWordsInFile("F2.txt");
    if (wordCount != -1) {
        cout << "Кількість слів у файлі F2: " << wordCount << endl;
    }

    return 0;
}
