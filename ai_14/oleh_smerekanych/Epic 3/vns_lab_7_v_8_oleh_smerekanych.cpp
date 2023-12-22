#include <iostream>
#include <climits>
#include <cstdarg>
#include <string>
using namespace std;

int min(int count, ...) {
    int minValue = INT_MAX;

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        int current = va_arg(args, int);
        if (current < minValue) {
            minValue = current;
        }
    }

    va_end(args);

    return minValue;
}

string getOldJapaneseYearName(int year) {
    const string jikkan[10] = {"KAN", "MODZI", "IN", "BO", "YO", "TI", "IZU", "HO", "INU", "SU"};
    const string junishi[12] = {"Mouse", "Bull", "Tiger", "Bunny", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Cock", "Dog", "Pig"};

    int jikkanIndex = (year - 4) % 10;  
    int junishiIndex = (year - 4) % 12; 

    return jikkan[jikkanIndex] + " " + junishi[junishiIndex];
}


string getZodiacSign(const string &monthName) {
    const string seasons[24] = {
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December",
        "First February", "Second February", "First March", "Second March", "First April", "Second April", "First May", "Second May", "First June", "Second June"
    };

    for (int i = 0; i < 24; ++i) {
        if (seasons[i] == monthName) {
            return seasons[i % 12]; 
        }
    }

    return "Unknown month";
}

int main() {
    
    int minResult = min(5, 10, 7, 15, 3, 8);
    cout << "Minimum number: " << minResult << endl;

    minResult = min(10, 23, 56, 12, 8, 45, 6, 32, 11, 4, 19);
    cout << "Minimum number: " << minResult << endl;

    minResult = min(12, 5, 2, 14, 18, 9, 25, 30, 7, 11, 16, 22, 13);
    cout << "Minimum number: " << minResult << endl;

    
    int year = 2023;
    std::string oldJapaneseName = getOldJapaneseYearName(year);
    std::cout << "Year " << year << " in the old Japanese calendar: " << oldJapaneseName << endl;

    string monthName = "February";  
    string zodiacSign = getZodiacSign(monthName);
    cout << "Month " << monthName << ": Zodiac Sign - " << zodiacSign << endl;

    return 0;
}
