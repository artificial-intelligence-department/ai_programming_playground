#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Функція для копіювання рядків з файлу F1 у файл F2
void copyLines(const char *inputFileName, const char *outputFileName, int start1, int end1, int start2) {
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Помилка при відкритті файлу для читання." << endl;
        return;
    }

    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Помилка при відкритті файлу для запису." << endl;
        inputFile.close();
        return;
    }

    string line;
    int currentLine = 0;

    // Копіюємо рядки, які починаються на "А" між n1 та n2
    while (getline(inputFile, line)) {
        currentLine++;
        if (currentLine >= start1 && currentLine <= end1 && !line.empty() && line[0] == 'A') {
            outputFile << line << endl;
        }
    }

    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    currentLine = 0;

    while (currentLine < start2 && getline(inputFile, line)) {
        currentLine++;
    }

    while (getline(inputFile, line)) {
        if (!line.empty()) {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();
}

int countWordsInLine(const string &line) {
    int wordCount = 0;
    istringstream iss(line);
    string word;

    while (iss >> word) {
        wordCount++;
    }

    return wordCount;
}

int main() {
    ofstream f1("F1.txt");
    f1 << "Apple pie\n";
    f1 << "Banana split with chocolate\n";
    f1 << "Alphabet soup and crackers\n";
    f1 << "Apricot jam on toast\n";
    f1 << "Avocado and tomato toast\n";
    f1 << "Aardvark goes on an exciting adventure\n";
    f1 << "Artichoke dip with spinach\n";
    f1 << "Cat takes a long nap under the sun\n";
    f1 << "Doghouse in the backyard\n";
    f1 << "Elephants march in a grand parade\n";
    f1.close();

    copyLines("F1.txt", "F2.txt", 1, 2, 5);

    ifstream f2("F2.txt");
    string lastLine;
    while (getline(f2, lastLine)) {
        if (!lastLine.empty()) {
        }
    }
    f2.close();

    int lastLineWordCount = countWordsInLine(lastLine);

    cout << "Contents of F2.txt after copying:" << endl;
    ifstream f2Print("F2.txt");
    cout << f2Print.rdbuf() << endl;
    f2Print.close();

    cout << "\nWord count in the last line of F2.txt: " << lastLineWordCount << endl;

    return 0;
}
