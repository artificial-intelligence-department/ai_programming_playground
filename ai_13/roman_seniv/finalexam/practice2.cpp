#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

double calculateSize(const string& surname) {
    int count = 0;
    for (char letter : surname) {   // використовую цикл for 
        if (tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'i' ||
            tolower(letter) == 'o' || tolower(letter) == 'u') {
            count++;
        }
    }
    return count * 0.8; // вказівник 
}

int main() {
    const int minLengh = 100;
    const int maxLengh = 130;
    const int minWidth = 50; // задаю цілочисельні костанти
    const int maxWidth = 100;

    string surname = "Seniv";
    double letterSize = calculateSize(surname); // використовую виклик функції

    int minBannerLength = max(minLengh, static_cast<int>(ceil(letterSize)));
    int centralChars = minBannerLength / 2;

    cout << "Writing from left to right:" << endl; // вивід

    int i = 0;
    do {
        cout << "X";
        i++;
    } while (i < centralChars);
    cout << surname << endl;

    cout << "Writing from right to left:" << endl; вивід

    i = 0;
    do {                   //використовую цикл do while 
        cout << "X";
        i++;
    } while (i < centralChars);
    cout << surname << endl;

    return 0;
}
