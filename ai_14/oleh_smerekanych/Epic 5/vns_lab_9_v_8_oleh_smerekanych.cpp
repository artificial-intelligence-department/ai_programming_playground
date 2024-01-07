#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void copy_lines_without_digits(const string& inputFile, const string& outputFile) {
    ifstream fin(inputFile);
    ofstream fout(outputFile);

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Unable to open files." << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        if (line.find_first_of("0123456789") == string::npos) {
            fout << line << '\n';
        }
    }

    fin.close();
    fout.close();
}

int countLinesStartingWithA(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Unable to open the file: " << filename << endl;
        return 0; 
    }

    int count = 0;
    string line;
    while (getline(file, line)) {
        if (!line.empty() && line[0] == 'A') {
            count++;
        }
    }

    file.close();
    return count;
}

int main() {
    const string inputFile = "F1.txt";
    const string outputFile = "F2.txt";

    copy_lines_without_digits(inputFile, outputFile);
    cout << "Task 1 completed. Check F2.txt for the result." << endl;

    int countA = countLinesStartingWithA(outputFile);
    if (countA != -1) {
        cout << "Task 2 completed. Number of lines starting with 'A' in F2.txt: " << countA << endl;
    }

    return 0;
}
