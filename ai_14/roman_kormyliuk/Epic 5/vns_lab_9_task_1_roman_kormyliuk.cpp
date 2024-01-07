#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Завдання 1: Створення та наповнення файлу F1
    ofstream f1("F1.txt");
    if (!f1.is_open()) {
        cerr << "Не вдалося відкрити файл F1.txt для запису." << endl;
        return 1;
    }

    cout << "Введіть слова для файлу F1 (введіть 'end' для завершення введення):\n";
    string userInput;
    while (true) {
        getline(cin, userInput);
        if (userInput == "end") {
            break;
        }
        f1 << userInput << endl;
    }
    f1.close();

    // Завдання 2: Копіювання рядків без слів на одну букву в файл F2
    ifstream f1_read("F1.txt");
    ofstream f2("F2.txt");
    if (!f1_read.is_open() || !f2.is_open()) {
        cerr << "Не вдалося відкрити файли для читання або запису." << endl;
        return 1;
    }

    string line;
    while (getline(f1_read, line)) {
        istringstream iss(line);
        bool contains_single_letter_word = false;

        // Перевірка кожного слова у рядку
        string word;
        while (iss >> word) {
            if (word.length() == 1) {
                contains_single_letter_word = true;
                break;
            }
        }

        // Копіювання рядка, якщо не містить слово на одну букву
        if (!contains_single_letter_word) {
            f2 << line << endl;
        }
    }

    f1_read.close();
    f2.close();

    // Завдання 3: Знаходження найкоротшого слова у файлі F2
    ifstream f2_read("F2.txt");
    if (!f2_read.is_open()) {
        cerr << "Не вдалося відкрити файл F2.txt для читання." << endl;
        return 1;
    }

    string shortest_word;
    bool first_word = true;

    while (f2_read >> line) {
        if (first_word || line.length() < shortest_word.length()) {
            shortest_word = line;
            first_word = false;
        }
    }
    f2_read.close();

    // Виведення результатів
    cout << "Найкоротше слово у файлі F2: " << shortest_word << endl;
    return 0;
}