#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

double calculateSize(const string& surname) {
    int count = 0;
    for (char letter : surname) {
        if (tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'i' ||
            tolower(letter) == 'o' || tolower(letter) == 'u') {
            count++;
        }
    }
    return count * 0.8;
}

int main() {
    const int minLengh = 100;
    const int maxLengh = 130;
    const int minWidth = 50;
    const int maxWidth = 100;

    string surname = "Seniv";
    double letterSize = calculateSize(surname);

    int minBannerLength = max(minLengh, static_cast<int>(ceil(letterSize)));
    int centralChars = minBannerLength / 2;

    cout << "Writing from left to right:" << endl;
    for (int i = 0; i < centralChars; ++i) {
        cout << "X";
    }
    cout << surname << endl;

    cout << "Writing from right to left:" << endl;
    cout << surname;
    for (int i = 0; i < centralChars; ++i) {
        cout << "X";
    }
    cout << endl;

    return 0;
}
