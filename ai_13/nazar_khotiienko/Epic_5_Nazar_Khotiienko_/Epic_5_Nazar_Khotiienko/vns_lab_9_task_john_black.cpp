#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    // Завдання 1: Створення та наповнення файлу F1
    int M;
    cout << "Введіть кількість слів для файлу F1: ";
    cin >> M;

    string mas[M];  // Змінив масив на вектор для уникнення помилок
    cout << "Введіть слів для файлу F1:\n";
    for (int i = 0; i < M; i++) {
        cin >> mas[i];
    }

    ofstream f1("F1.txt");
    if (!f1.is_open()) {
        cerr << "Не вдалося відкрити файл F1.txt для запису." << endl;
        return 0;
    }

    for (int i = 0; i < M; i++) {
        f1 << mas[i] << endl;
    }
    f1.close();

    // Завдання 2: Знаходження найкоротшого слова у файлі F1
    ifstream f1_read("F1.txt");  // Змінив ім'я файлу на правильне
    if (!f1_read.is_open()) {
        cerr << "Не вдалося відкрити файл F1.txt для читання." << endl;
        return 0;
    }

    string shortt;
    bool first_word = true;
    string line;  // Додав змінну line, яку ви використовуєте при читанні файла

    while (f1_read >> line) {
        if (first_word || line.length() < shortt.length()) {
            shortt = line;
            first_word = false;
        }
    }
    f1_read.close();

    // Виведення результатів
    cout << "Найкоротше слово у файлі F1: " << shortt << endl;
    return 0;
}
