#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Функція для підрахунку голосних букв у рядку
int countVowels(const string& line) {
    const string vowels = "aeiouAEIOU";
    return count_if(line.begin(), line.end(), [&vowels](char c) {
        return find(vowels.begin(), vowels.end(), c) != vowels.end();
    });
}

int main() {
    // Відкритя файлів для читання та запису
    ifstream inputFile("F1.txt");
    ofstream outputFile("F2.txt");

    // Задаємо номери рядків N1 та N2
    int N1 = 3;
    int N2 = 7;

    // Перевірка на помилку, (чи файли вдалося відкрити)
    if (!inputFile) {
        cerr << "ERROR 404_1" << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "ERROR 404_2" << endl;
        return 1;
    }

    string line;
    int maxVowelsLine = -1;
    int maxVowelsCount = 0;

    // Читаємо рядки з файлу F1
    for (int i = 1; i <= N2 && getline(inputFile, line); ++i) {
 
        // Перевіряємо, чи поточний рядок входить в діапазон N1-N2 та не містить букву 'A'
        if (i >= N1 && i <= N2 && line.find('A') == string::npos) {
            // Записуємо відповідні рядки у файл F2
            outputFile << line << endl;

            // Знаходимо рядок з найбільшою кількістю голосних букв
            int vowelsCount = countVowels(line);
            if (vowelsCount > maxVowelsCount) {
                maxVowelsCount = vowelsCount;
                maxVowelsLine = i;
            }
        }
    }

    // Закриваємо файли
    inputFile.close();
    outputFile.close();

    // Виводимо результат
    if (maxVowelsLine != -1) {
        cout << maxVowelsLine << endl;
    } else {
        cout << "there's no lines that i need"<< endl;
    }

    return 0;
}

