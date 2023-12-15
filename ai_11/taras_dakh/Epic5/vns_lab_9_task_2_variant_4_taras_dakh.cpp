#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Задання імен файлів
    string f1FileName = "F1";
    string f2FileName = "F2";

    // Створення та заповнення текстового файлу F1
    ofstream f1(f1FileName);
    if (!f1.is_open()) {
        cerr << "Помилка відкриття файлу " << f1FileName << endl;
        return 1;
    }

    cout << "Введіть 10 рядків для файлу F1:\n";
    for (int i = 0; i < 10; ++i) {
        string input;
        cout << "Рядок " << i + 1 << ": ";
        getline(cin, input);
        f1 << input << endl;
    }

    f1.close();

    // Завдання 1: Копіювання рядків з F1 у F2, починаючи з 4-го рядка
    ifstream f1Read(f1FileName);
    ofstream f2(f2FileName);

    if (!f1Read.is_open() || !f2.is_open()) {
        cerr << "Помилка відкриття файлів для завдання 1." << endl;
        return 1;
    }

    string line;
    int lineCount = 0;

    while (getline(f1Read, line)) {
        lineCount++;
        if (lineCount >= 4) {
            f2 << line << endl;   //Зчитується кожен рядок з файлу F1. Якщо лічильник lineCount більший або рівний 4, рядок записується у файл F2
        }
    }

    f1Read.close();
    f2.close();

    cout << "Завдання 1 виконано. Результат збережено у файлі " << f2FileName << endl;

    // Завдання 2: Підрахунок кількості символів в останньому слові F2
    ifstream f2Read(f2FileName);

    if (!f2Read.is_open()) {
        cerr << "Помилка відкриття файлу " << f2FileName << endl;
        return 1;
    }

    string lastLine;

    while (getline(f2Read, line)) {
        lastLine = line;
    }

    f2Read.close();

    // Знаходження останнього слова
    size_t lastSpace = lastLine.find_last_of(' ');
    if (lastSpace != string::npos) {
        string lastWord = lastLine.substr(lastSpace + 1);
        // Виведення результату
        cout << "Останнє слово в F2: " << lastWord << endl;
        cout << "Кількість символів в останньому слові F2: " << lastWord.length() << endl;
    } else {
        cerr << "Помилка: рядок не містить пробілів." << endl;
    }

    return 0;
}