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