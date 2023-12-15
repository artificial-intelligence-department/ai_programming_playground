#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main() {
    // Створення файлу F1.txt з 10 рядками
    ofstream file("F1.txt");
    if (file.is_open()) {
        for (int i = 1; i <= 10; i++) {
            file << "Це рядок номер " << i << endl;
        }
        file.close();
    }

    // Копіювання рядків, починаючи з 4-го, з файлу F1.txt до файлу F2.txt
    ifstream file1("F1.txt");
    ofstream file2("F2.txt");
    string line;
    int line_number = 0;

    if (file1.is_open() && file2.is_open()) {
        while (getline(file1, line)) {
            line_number++;
            if (line_number >= 4) {
                file2 << line << endl;
            }
        }
        file1.close();
        file2.close();
    }

    // Підрахунок кількості символів в останньому слові F2
    ifstream file2_read("F2.txt");
    string last_word;
    if (file2_read.is_open()) {
        while (file2_read >> last_word) {}
        file2_read.close();
    }

    int num_chars = last_word.length();
    cout << "Кількість символів в останньому слові F2: " << num_chars << endl;

    return 0;
}