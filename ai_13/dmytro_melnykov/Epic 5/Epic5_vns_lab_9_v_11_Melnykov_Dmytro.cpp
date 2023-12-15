#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>

using namespace std;


int shortestword(const vector<string>& lines) {//номер рядка з найкоротшим словом
    int shortestRow = -1;
    size_t shortestlength = numeric_limits<size_t>::max(); //початкове значення перед найменшим

    for (int i = 0; i < lines.size(); ++i) {
        istringstream s(lines[i]);
        string word;

        while (s >> word) {
            if (word.length() < shortestlength) { //  довжинa кожного слова та знаходимо найкоротше
                shortestlength = word.length();
                shortestRow = i;
            }
        }
    }

    return shortestRow;
}

void copylines(const string& inputFile, const string& outputFile) { //копіюємо рядки з F1  F2 крім shortrow
    ifstream in(inputFile);
    ofstream out(outputFile);

    if (!in.is_open()) {
        cout << "Помилка відкриття файлу " << inputFile << endl;// для читання 
        return;
    }

    if (!out.is_open()) {
        cout << "Помилка відкриття файлу " << outputFile << " для запису." << endl;
        in.close();
        return;
    }

    vector<string> lines;
    string line;

    
    while (getline(in, line)) { //рядки з файлу F1
        lines.push_back(line);
    }

   
    int shortestRow = shortestword(lines); // номер рядка з найкоротшим словом


    for (int i = 0; i < lines.size(); ++i) {// Копіюємо рядки F2
        if (i != shortestRow) {
            out << lines[i] << endl;
        }
    }

    cout << "Номер рядка з найкоротшим словом: " << shortestRow + 1 << endl;

    in.close();
    out.close();// закриває файлові потоки
}

int main() {
    //  функція для копіювання рядків та виведення номера рядка з найкоротшим словом
    copylines("F1.txt", "F2.txt");

    return 0;
}
