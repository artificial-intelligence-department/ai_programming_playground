#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Функція для обчислення кількості голосних букв у рядку
int countVowels(const string& str) {
    int vowels = 0;
    for (char c : str) {
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u')
            vowels++;
    }
    return vowels;
}

// Функція для створення банера з прізвища
string createBanner(const string& surname, int fieldLengthYards, double letterWidthcoreYards) {
    string banner = "";
    while (fieldLengthYards > 0) {
        if (fieldLengthYards > letterWidthcoreYards) {
            for (int i = 0; i < surname.size(); i++) {
                cout << surname[i];
                banner += surname[i];
            }
        }
        else {
            for (int i = 0; i < fieldLengthYards; i++) {
                cout << surname[i];
                banner += surname[i];
            }
        }
        fieldLengthYards -= (int)letterWidthcoreYards;
    }
    return banner;
}

// Функція для виводу центральних 3 літер з рядка
void printCentralLetters(const string& str) {
    cout << "Central 3 letters: ";
    cout << str[(str.size() / 2) - 1] << " ";
    cout << str[str.size() / 2] << " ";
    cout << str[(str.size() / 2) + 1] << " ";
}

int main() {
    string surname = "Salishcheva";
    int footballFieldLengthYards = 100; // За варіантом

    // Обчислення кількості голосних букв у прізвищі
    int vowels = countVowels(surname);

    // Обчислення ширини букви разом з інтервалом у ярдах
    double letterWidthcoreYards = vowels * 0.8 * 3.2808 * 3;

    // Виведення найменшої довжини банера
    cout << "The shortest length of the banner: " << letterWidthcoreYards << " yards" << endl;

    // Створення банера з прізвища при написанні з лівого краю поля до правого
    cout << endl << "When writing the surname from the left edge of the field —- to the right: \n";
    string banner1 = createBanner(surname, footballFieldLengthYards, letterWidthcoreYards);
    cout << endl << endl;

    // Виведення центральних 3 літер з банера1
    printCentralLetters(banner1);
    cout << endl << endl;

    // Створення банера з прізвища при написанні з правого краю поля <— до лівого
    cout << endl << "When writing the surname from the right edge of the field —- to the left: \n";
    std::string banner2 = createBanner(surname, footballFieldLengthYards, letterWidthcoreYards);
    cout << endl << endl;

    // Виведення центральних 3 літер з банера2
    printCentralLetters(banner2);
    cout << endl << endl;

    // Запис відповіді у файл
    ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        outputFile << "The shortest length of the banner: " << letterWidthcoreYards << " yards" << endl;
        outputFile << "Banner from left to right: " << banner1 << endl;
        outputFile << "Central 3 letters: " << banner1[(banner1.size() / 2) - 1] << " "
            << banner1[banner1.size() / 2] << " "
            << banner1[(banner1.size() / 2) + 1] << endl;
        outputFile << "Banner from right to left: " << banner2 << endl;
        outputFile << "Central 3 letters: " << banner2[(banner2.size() / 2) - 1] << " "
            << banner2[banner2.size() / 2] << " "
            << banner2[(banner2.size() / 2) + 1] << endl;
        outputFile.close();
        cout << "Output written to output.txt" << endl;
    }
    else {
        cout << "Unable to open the output file." << endl;
    }

    return 0;
}
