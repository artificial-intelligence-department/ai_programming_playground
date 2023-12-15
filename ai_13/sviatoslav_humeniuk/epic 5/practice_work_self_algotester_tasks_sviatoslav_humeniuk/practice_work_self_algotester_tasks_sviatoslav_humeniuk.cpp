//Програма аналізує текстовий файл та видає строку з найбільшою кількістю голосних літер
#include <iostream>
#include <fstream> //Бібліотека, що працює із потоками інформації у файлах
#include <vector>
#include <algorithm> //Застосовуємо для команди count_if

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    ifstream F1("F1.txt"); // Відкриває або за потреби створює файл F1 для читання
    ofstream F2("F2.txt"); // Створює або редагує F2 та вносить дані 

    if (!F1.is_open() || !F2.is_open()) {
        cout << "fail" << endl; // Також може використовуватись cerr для виводу повідомлення про помилку
        return 1;
    }

    vector<string> lines;
    string line;
    while (getline(F1, line)) {
        lines.push_back(line);
    }

    int maxvwls = 0;
    int maxvwlsline = 0;
    for (int i = 0; i < lines.size(); i++) {
        int vwlscount = count_if(lines[i].begin(), lines[i].end(), isVowel); // За допомогою функції bool підраховуємо кількість голосних
        if (vwlscount > maxvwls) {
            maxvwls = vwlscount;
            maxvwlsline = i;
        }
    }

    for (int i = 0; i < lines.size(); i++) {
        if (i != maxvwlsline) {
            F2 << lines[i] << endl;
        }
    }

    cout << "number of line: " << maxvwlsline + 1 << endl;

    F1.close();
    F2.close();

    return 0;
}
