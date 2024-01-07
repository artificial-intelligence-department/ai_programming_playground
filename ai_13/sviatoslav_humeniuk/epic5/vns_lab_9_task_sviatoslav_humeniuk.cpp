// Підрахувати кількість символів у останньому слові F2
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ifstream f1("F1.txt");    // Читання файлу F1

    if (!f1.is_open()) {
        cout << "unable to open f1" << endl; // Для виводу помилок також можемо використовувати команду cerr (який не зберігається у буфері обміну)
        return 1;
    }

    ofstream f2("F2.txt");    // Створення та відкриття файлу F2

    if (!f2.is_open()) {
        cout << "unable to create f2" << endl;
        return 1;
    }

    // Пропустити перші 3 рядки в файлі F1
    string line;
    for (int i = 0; i < 3; ++i) {
        if (!getline(f1, line)) {
            cout << "scarce of lines in f1" << endl;
            return 1;
        }
    }

    while (getline(f1, line)) {    // Скопіювати решту рядків у файл F2
        f2 << line << endl;
    }

    f1.close();    // Закриття файлів
    f2.close();

    ifstream f2ForCount("F2.txt");// Відкриття файлу F2 для підрахунку кількості символів у останньому слові

    if (!f2ForCount.is_open()) {    
        cout << "unable to open f2" << endl;
        return 1;
    }

    string lastLine;    // Зчитування останнього рядка

    while (getline(f2ForCount, line)) {
        lastLine = line;
    }

    f2ForCount.close();    // Закриття файлу F2 для підрахунку


    stringstream ss(lastLine);    // Використання stringstream для підрахунку кількості слів у останньому рядку
    string lastWord;
    while (ss >> lastWord) {
    }

    int charCount = lastWord.size() - 1; // Віднімаємо одиницю, оскільки програма сприймає крапку, як частину слова

    cout << "there're " << charCount << " characters in the last word" << endl;

    return 0;
}