#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Field //Вимога 19: в коді використано свою структуру даних

{
    const double WIDTH_PER_VOWEL = 0.8; // Вимога #3 - дійсна змінна
    const int YARDS_TO_INCHES = 36;     // Вимога #4 - цілочисельна константа

    double lengthYards;  // Вимога #2 - дійсна змінна
    double lengthInches; // Вимога #2 - дійсна змінна

    Field(double lengthYards) : lengthYards(lengthYards), lengthInches(lengthYards * YARDS_TO_INCHES) {}

    int lettersOnField(const string &surname) // Вимога #15 - параметри та аргументи функції
    {
        int vowels = 0;        // Вимога #1 - цілочисельна змінна
        for (char c : surname) // Вимога #10 - for цикл
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') // Вимога #5 - умовні оператори та розгалуження
            {
                vowels++;
            }
        }
        return static_cast<int>(lengthInches / (vowels * WIDTH_PER_VOWEL)); // Вимога #14 - математичні операції
    }
};

int main()
{
    string surname = "Kuznietsova"; // Вимога #17 - оператор введення даних

    Field field(120); // Вимога #9 - оператори введення даних

    int lettersCount = field.lettersOnField(surname);   // Вимога #15 - параметри та аргументи функції
    double centralWidth = field.lengthInches / 2.0;     // Вимога #3 - дійсна змінна
    int start = static_cast<int>(centralWidth - 177.0); // Вимога #1 - цілочисельна змінна
    int end = static_cast<int>(centralWidth + 177.0);   // Вимога #1 - цілочисельна змінна

    cout << "\nКількість букв на полі: " << lettersCount << endl; // Вимога #17 - оператор виведення даних

    for (int i = start; i < end && i < surname.length(); i++) // Вимога #10 - for цикл
    {
        cout << surname[i]; // Вимога #17 - оператор виведення даних
    }
    cout << endl;

    for (int i = end - 1; i >= start && i < surname.length(); i--) // Вимога #10 - for цикл
    {
        cout << surname[i]; // Вимога #17 - оператор виведення даних
    }
    cout << endl;

    return 0;
}
