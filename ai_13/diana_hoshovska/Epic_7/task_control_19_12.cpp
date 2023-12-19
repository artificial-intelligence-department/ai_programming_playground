//  Загальні відомості
// В американській системі виміру довжин використовуються ярди, фути, дюйми. 1 Ярд = 3 фути. 1 Фут = 12 дюймів. 1 Дюйм = 2.54 см.
// Футбольні поля мають можуть мати різну довжину
// Довжина: мінімум 100 ярдів, максимум 130 ярдів.
// Ширина: мінімум 50 ярдів, максимум 100 ярдів.

// Довжина задається по варіанту 100 - 110 -120 - 130 для кожної групи інший розмір поля. ШІ -11  100 ярдів, ШІ -12 110 ярдів … і т.д.

// Використовуючи Ваше прізвище розрахувати найменшу довжину, яка необхідна для розміщення банера з Вашим прізвищем.
//  За умови, що прізвище можна записати лише в 1 ряд, а ширина букви(разом з інтервалом між символами) = кількості голосних букв 
//у Вашому прізвищі * 0.8 метра.
// На основі обчислених розмірів букви визначити символи, які будуть знаходитись на 3-х центральних(по довжині) метрах поля. 
// Обчислення зробити для 2-х випадків:
// 1) при написанні прізвища з лівого краю поля —>  до правого
// 2) при написанні прізвища з правого краю поля <—  до лівого.
// Результат записати.

#include <iostream>
using namespace std;

int holosny(const string& surname, int &holosnyCount) {
    for (int i = 0; i < surname.length(); i++) {
        if (surname[i] == 'a' || surname[i] == 'o' || surname[i] == 'e' || surname[i] == 'i' || surname[i] == 'u' || surname[i] == 'y') {
            holosnyCount++;
        }
    }
    return 0;
}

int main() {
    int yard = 3, foot = 12;
    float dyujm = 2.54, length; // length = 120 yard

    length = yard * foot * dyujm * 120; // in cm
    cout << "Length: " << length << endl;

    int holosnyCount = 0;
    // surname Hoshovska
    // holosni - o, o, a;
    string surname = "Hoshovska";
    holosny(surname, holosnyCount);
    cout << "Number of holosny: " << holosnyCount << endl;

    double width = holosnyCount * 0.8, bannerLength = width;

    int startLeft = (surname.length() - 3) / 2;
    int endLeft = startLeft + 3;
    string charsLeft = surname.substr(startLeft, 3);

    int startRight = (surname.length() - 3) / 2;
    int endRight = startRight + 3;
    string charsRight = surname.substr(startRight - 2, 3);

    cout << "Starting from the left: " << charsLeft << endl;
    cout << "Starting from the right: " << charsRight << endl;

    return 0;
}
