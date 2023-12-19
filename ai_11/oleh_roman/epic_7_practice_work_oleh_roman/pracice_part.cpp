// Загальні відомості
// В американській системі виміру довжин використовуються ярди, фути, дюйми. 1 Ярд = 3 фути. 1 Фут = 12 дюймів. 1 Дюйм = 2.54 см.
// Футбольні поля мають можуть мати різну довжину
// Довжина: мінімум 100 ярдів, максимум 130 ярдів.
// Ширина: мінімум 50 ярдів, максимум 100 ярдів.

// // Довжина задається по варіанту 100 - 110 -120 - 130 для кожної групи інший розмір поля. ШІ -11  100 ярдів, ШІ -12 110 ярдів … і т.д.

// Використовуючи Ваше прізвище розрахувати найменшу довжину, яка необхідна для розміщення банера з Вашим прізвищем.
//  За умови, що прізвище можна записати лише в 1 ряд, а ширина букви(разом з інтервалом між символами) = кількості голосних букв у Вашому прізвищі * 0.8 метра.
// На основі обчислених розмірів букви визначити символи, які будуть знаходитись на 3-х центральних(по довжині) метрах поля. 
// Обчислення зробити для 2-х випадків:
// 1) при написанні прізвища з лівого краю поля —>  до правого
// 2) при написанні прізвища з правого краю поля <—  до лівого.
// Результат записати.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

bool Perevirka(char ch);
    // використовуються функції
vector<char> findCentralLetters(const string& surname, double letterWidth, double fieldLength, double centralLength) {
    double startCentral = (fieldLength - centralLength) / 2;
    double endCentral = startCentral + centralLength;
    vector<char> centralLetters;

    double currentPosition = 0;
    // використання різних циклів
    while (currentPosition < fieldLength) {
        for (char letter : surname) {
            double letterEnd = currentPosition + letterWidth;

            if ((currentPosition < endCentral && letterEnd > startCentral) || 
                (currentPosition >= startCentral && letterEnd <= endCentral)) {
                centralLetters.push_back(letter);
            }
            currentPosition += letterWidth;
            if (currentPosition >= fieldLength) break;  // Зупиняємося, якщо досягли кінця поля
        }
    }
    return centralLetters;
}



bool Perevirka(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int golosni(const string& inputFile) {
    ifstream file(inputFile);
    // зчитування прізвище з файлу
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return -1;
    }

    char ch;
    int consonantCount = 0;

    while (file.get(ch)) {
        if (Perevirka(ch)) {
            ++consonantCount;
        }
    }

    file.close();
    return consonantCount;
}

double YardsToMeters(double yard) {
    const double yard_per_meters = 0.9144;
    return yard * yard_per_meters;
}

int main() {
    const string filename = "MySecondName.txt";
    // використовуємо констанний тип даних
    string surname = "Roman";
    // використовуємо тип даних 'стрінг'
    int AmountOfGolosni = golosni("MySecondName.txt");
    // використовуємо цілочисельні змінні
    double letterWidth = AmountOfGolosni*0.8; 
    // використовуємо тип дахиз плаваючою комою
    double fieldLength = 100; 
    fieldLength = YardsToMeters(fieldLength);
    double bannerLength = surname.length() * letterWidth; 
    double centralLength = 3;

    vector<char> centralLtoR = findCentralLetters(surname, letterWidth, fieldLength, centralLength);

    string reversedSurname = surname;
    reverse(reversedSurname.begin(), reversedSurname.end());
    vector<char> centralRtoL = findCentralLetters(reversedSurname, letterWidth, fieldLength, centralLength);

    cout << "Central letters (left to right): ";
    for (char letter : centralLtoR) {
        cout << letter;
    }
    cout << endl;

    cout << "Central letters (right to left): ";
    for (char letter : centralRtoL) {
        cout << letter;
    }
    cout << endl;

    return 0;
}