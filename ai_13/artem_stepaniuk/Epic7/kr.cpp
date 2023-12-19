#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

const int MIN_YARDS = 100;
const int MAX_YARDS = 130;

int countVowel(const char* surname) {
    int count = 0;
    while (*surname) {
        char ch = tolower(*surname);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
        surname++;
    }
    return count;
}

double calculateLetterSize(const char* surname) {
    int vowelCount = countVowel(surname);
    return vowelCount * 0.8;
}

void writeToFile(const char* result) {
    std::ofstream file("Result.txt");
    file << result;
    file.close(); 
}

int main() {
    int minLength = MAX_YARDS;
    const char* mySurname = "Stepanyuk";
    double letterSize = calculateLetterSize(mySurname);
    int centralMeters = 300;

    for (int length = MIN_YARDS; length <= MAX_YARDS; length++) {
        int symbolsLeftToRight = static_cast<int>(length * 0.9144 / letterSize);
        int startLeftToRight = (symbolsLeftToRight-strlen(mySurname)) / 2;
    
        int SymbolsRightToLeft = static_cast<int>(length* 0.9144 / letterSize);
        int startRightToLeft = SymbolsRightToLeft - strlen(mySurname) - startLeftToRight;

        if (startLeftToRight >= 0 && startRightToLeft >= 0 && symbolsLeftToRight <= length && SymbolsRightToLeft <= length) {
        if(length < minLength) {
            minLength = length;
        }

        char result [1000];
        sprintf(result, "Length: %d yards\nSymbols Left to Right: %d\nStart Left to Right: %d\nSymbols Right to Left:%d\nStart Right to Left: %d\n\n",
        length, symbolsLeftToRight, startLeftToRight, symbolsLeftToRight, startLeftToRight, SymbolsRightToLeft, startRightToLeft);

        writeToFile(result);    
    }
}

std::cout << "Min Length: " << minLength << " yards\n";

return 0;
}
//1) Цілочисельна змінна є (length, minLength, symbolsLeftToRight, и т.д.)
//2) Дійсна Змінна є (letterSize)
//3) Дійсна з подвійною точністю теж (знов letterSize)
//4) Цілочисельна константа Так (MIN_YARDS, MAX_YARDS)
//5) Умовні операторі теж є для перевірки розміщення банера на полі
//6) Одновимірний масив result
//7) Двовимірного масиву в мене у коді нема
//8) цикл do while використовується у функції countVowel
//9) While теж є у головній частині коду
//10) for цикл Так, використовується у головній частині коду
//11) break і continue я не використовував
//12) Перевантаження функції я не використовував
//13) Рекурсивну функцію я не використовував
//14) Праметри та аргументи функції були, наприклад countVowels та calculateLetterSize
//15) Функції роботи з файлами були (writeToFile)
//16) Оператори виведення та введення данних були, я використовував std::cout