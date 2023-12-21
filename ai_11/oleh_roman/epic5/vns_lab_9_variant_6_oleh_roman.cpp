#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

bool Perevirka(char ch);
void copyLines(const string& inputFile, const string& outputFile, int N, int K);
int Prugolosni(const string& inputFile);

int main() {
    int N, K;
    cout << "Enter N:" << endl;
    cin >> N;
    cout << "Enter K:" << endl;
    cin >> K;
    copyLines("F1.txt", "F2.txt", N, K);

    int consonantCount = Prugolosni("F2.txt");

    if (consonantCount >= 0) {
        cout << "Number of consonants in F2: " << consonantCount << endl;
    } else {
        cerr << "Error counting consonants." << endl;
    }
    /* cerr призначений для виведення повідомлень про помилки, і він надає незбуферизований вивід. 
    Це означає, що повідомлення будуть виводитися без затримок або буферизації, що є важливим у випадках, 
    коли програма може закінчитися через помилку та важливо вивести повідомлення про цю помилку негайно.
    */
    return 0;
}

bool Perevirka(char ch) {
    ch = tolower(ch);
    // tolower призначена для зменшення регістру літери
    return (ch >= 'a' && ch <= 'z' && ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u');
}

void copyLines(const string& inputFile, const string& outputFile, int N, int K) {
    ifstream f1(inputFile);
    // ifstream для читання
    ofstream f2(outputFile);
    /*ofstream для вписування. Також вона очищає цей файл. 
    Якщо такого файлу не існує, то ця команда його створить.
    якщо потрібно щось записати і не очищати то ofstream f2(outputFile, ios::app);
    */
    if (!f1.is_open() || !f2.is_open()) {
        cerr << "Error opening files." << endl;
        return;
    }

    string line;
    int currentLine = 1;

    while (getline(f1, line) && currentLine <= K) {
        if (currentLine >= N) {
            f2 << line << endl;
        }
        ++currentLine;
    }

    f1.close();
    f2.close();
}

int Prugolosni(const string& inputFile) {
    ifstream file(inputFile);

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return -1;
    }

    char ch;
    int consonantCount = 0;

    while (file.get(ch)) {
        if (Perevirka(ch)) {
            ++consonantCount;
        }
    }

    file.close();
    return consonantCount;
}
