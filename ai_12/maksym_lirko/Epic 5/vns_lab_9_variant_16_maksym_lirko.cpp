#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_to_file(const string& file_from, const string& file_to, int N1, int N2) {
    ifstream File1(file_from);
    ofstream File2(file_to, ios::app);

    if (!File1.is_open() || !File2.is_open()) {
        return Failure;
    }

    string content;
    int currentLine = 0;

    while (getline(File1, content)) {
        currentLine++;
        if (currentLine >= N1 && currentLine <= N2) {
            File2 << content << endl;
        }
    }

    File1.close(), File2.close();
    return Success;
}

int Word_Counter(const string& file_from) {
    ifstream File1(file_from);
    string firstLine;
    int counter = 0;

    if (getline(File1, firstLine)) {
        istringstream ss(firstLine);
        string word;
        while (ss >> word) {
            counter++;
        }
    }

    File1.close();
    return counter;
}

bool startsWithAendsWithZ(const string& file_from) {
    return (file_from.front() == 'A') && (file_from.back() == 'z');
}

int main() {
    int N1, N2;

    string File1 = "start.txt";
    string File2 = "final.txt";
    string content;

    ofstream clearFile(File1, ios::trunc);
    clearFile.close();

    ofstream clearFile2(File2, ios::trunc);
    clearFile2.close();

    for (int i = 0; i < 9; i++) {
        cout << "Type " << i + 1 << " line of text: " << endl;
        getline(cin, content);
        ofstream writeToFile(File1, ios::app);
        writeToFile << content << endl;
        writeToFile.close();
    }

    cout << "Enter the range of strings: " << endl;
    cin >> N1 >> N2;

    cout << "Strings starting with 'A' and ending with 'z' placed between " << N1 << " and " << N2 << endl;

    copy_to_file(File1, File2, N1, N2);
    int counter1 = Word_Counter(File2);

    cout << "Number of words in the first line of F2: " << counter1 << endl;

    return 0;
}
