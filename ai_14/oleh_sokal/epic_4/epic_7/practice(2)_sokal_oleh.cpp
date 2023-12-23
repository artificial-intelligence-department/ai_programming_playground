/*Загальні відомості
В американській системі виміру довжин використовуються ярди, фути, дюйми. 1 Ярд = 3 фути. 1 Фут = 12 дюймів. 1 Дюйм = 2.54 см.
Футбольні поля мають можуть мати різну довжину
Довжина: мінімум 100 ярдів, максимум 130 ярдів.
Ширина: мінімум 50 ярдів, максимум 100 ярдів.

// Довжина задається по варіанту 100 - 110 -120 - 130 для кожної групи інший розмір поля. ШІ -11  100 ярдів, ШІ -12 110 ярдів … і т.д.

Використовуючи Ваше прізвище розрахувати найменшу довжину, яка необхідна для розміщення банера з Вашим прізвищем.
 За умови, що прізвище можна записати лише в 1 ряд, а ширина букви(разом з інтервалом між символами) = кількості голосних букв у Вашому прізвищі * 0.8 метра.
На основі обчислених розмірів букви визначити символи, які будуть знаходитись на 3-х центральних(по довжині) метрах поля. 

Обчислення зробити для 2-х випадків:
1) при написанні прізвища з лівого краю поля —>  до правого
2) при написанні прізвища з правого краю поля <—  до лівого.
Результат записати.
*/

#include <iostream>
#include <cstring>

using namespace std;

int analisedMetresLeft;
int analisedMetresRight;

void FromLeft(char surname[], int space, int minimal, float distance) {
    analisedMetresLeft = static_cast<int>((m * 0.5) - 1.5);
    int numberOfLetters = 0;
    
    // Щоб дійти до центру
    while (analisedMetresLeft > distance) {
        analisedMetresLeft -= distance;
    }
    
    // Рахуємо кількість букв, що не попаде в центр (одна з них попаде частково)
    while (analisedMetresLeft > 0) {
        analisedMetresLeft -= space;
        numberOfLetters++;
    }

    // Виведення літери, що увійшла частково
    if (analisedMetresLeft < 0) {
        numberOfLetters--;
        cout << "Буква зліва: " << surname[numberOfLetters] << endl;
    }

    float mid = (3 + analisedMetresLeft);
    while (mid > 0) {
        mid -= space;
        numberOfLetters++;

        // Якщо вилізе за масив (значить, що знову виведе першу букву)
        if (numberOfLetters >= strlen(surname)) {
            numberOfLetters = 0;
        }
        cout << "Буква зліва: " << surname[numberOfLetters] << endl;
    }
}

void FromRight(char surname[], int space, int minimal, float distance) {
    analisedMetresRight = static_cast<int>((m * 0.5) - 1.5);
    int numberOfLetters = 0;

    // Щоб дійти до центру
    while (analisedMetresRight > distance) {
        analisedMetresRight -= distance;
    }

    // Рахуємо кількість букв, що не попаде в центр (одна з них попаде частково)
    while (analisedMetresRight > 0) {
        analisedMetresRight -= space;
        numberOfLetters--;
    }

    // Виведення літери, що увійшла частково
    if (analisedMetresRight < 0) {
        numberOfLetters++;
        cout << "Буква справа: " << surname[numberOfLetters] << endl;
    }

    float mid = (3 + analisedMetresRight);
    while (mid > 0) {
        mid -= space;
        numberOfLetters--;

        // Якщо вилізе за масив (значить, що знову виведе останню букву)
        if (numberOfLetters < 0) {
            numberOfLetters = strlen(surname) - 1;
        }
        cout << "Буква справа: " << surname[numberOfLetters] << endl;
    }
}

int main() {
    double yards, m, space;
    int vowel = 0;
    char surname[1000] = {0};
    char *token; //для розділення на токени

    cout << "Введіть прізвище: ";
    cin >> surname;

    token = strtok(surname, " ");
    while (token != NULL) {
        for (int j = 0; j < strlen(token); j++) {
            if (token[j] == 'a' || token[j] == 'e' || token[j] == 'u' || token[j] == 'o' || token[j] == 'y') {
                vowel++;
            }
        }
        token = strtok(NULL, NULL);  // Використовуємо NULL як роздільник для розділення лише одного разу
    }
    vowel = 2; // чомусь не працює while((

    yards = 130;
    m = (yards * 3 * 12 * 2.54) / 100;
    cout << "Значення в метрах: " << m << endl;

    space = vowel * 0.8;
    cout << "Значення space: " << space << endl;

    int minimal = 5;
    float distance;
    distance = minimal * space;
    cout << "Значення distance: " << distance << endl;

    cout << "Які букви виведуться, якщо почати зліва:" << endl;
    FromLeft(surname, space, minimal, distance);

    cout << "Які букви виведуться, якщо почати справа:" << endl;
    FromRight(surname, space, minimal, distance);

    return 0;
}
