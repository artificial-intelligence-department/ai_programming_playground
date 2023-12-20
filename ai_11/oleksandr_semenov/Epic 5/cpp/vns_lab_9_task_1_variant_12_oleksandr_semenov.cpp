#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Функція для підрахунку кількості голосних букв у рядку
int countVowels(const string& str) {
    int vowelCount = 0;
    for (char ch : str) {
        if (isalpha(ch) && (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                                 ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')) {
            vowelCount++;
        }
    }
    return vowelCount;
}

// Функція для знаходження номеру рядка з найбільшою кількістю голосних букв
int findRowWithMostVowels(const vector<string>& lines) {
    int maxVowelCount = -1;
    int maxVowelRow = -1;

    for (int i = 0; i < lines.size(); ++i) {
        int currentVowelCount = countVowels(lines[i]);
        if (currentVowelCount > maxVowelCount) {
            maxVowelCount = currentVowelCount;
            maxVowelRow = i;
        }
    }

    return maxVowelRow;
}

int main() {
    // Створення та заповнення файлу F1
    ofstream f1("D:\\lab_9_test_1\\F1.txt");
    f1 << "Hello world!\n";
    f1 << "This is a sample text.\n";
    f1 << "Programming is fun.\n";
    f1 << "C++ is powerful.\n";
    f1 << "Learning never ends.\n";
    f1 << "OpenAI is amazing.\n";
    f1 << "Artificial Intelligence\n";
    f1 << "GPT-3.5\n";
    f1 << "Testing vowels.\n";
    f1 << "Have a great day!\n";
    f1.close();

    // Відкриття файлу F1 для читання
    ifstream inFile("D:\\lab_9_test_1\\F1.txt");

    // Перевірка на успішність відкриття файлу
    if (!inFile.is_open()) {
        cerr << "Помилка відкриття файлу F1 для читання." << endl;
        return 1;  // Повернення коду помилки
    }

    // Зчитування рядків з файлу F1
    vector<string> lines;
    string line;
    while (getline(inFile, line)) {
        lines.push_back(line);
    }

    // Закриття файлу F1
    inFile.close();

    // Завдання 1: Копіювання рядків (крім рядка з найбільшою кількістю голосних букв) у файл F2
    int rowWithMostVowels = findRowWithMostVowels(lines);
    ofstream f2("D:\\lab_9_test_2\\F2.txt");
    for (int i = 0; i < lines.size(); ++i) {
        if (i != rowWithMostVowels) {
            f2 << lines[i] << '\n';
        }
    }
    f2.close();

    // Завдання 2: Виведення номеру рядка з найбільшою кількістю голосних букв
    cout << "Номер рядка з найбільшою кількістю голосних букв: " << rowWithMostVowels + 1 << endl;

    return 0;
}
