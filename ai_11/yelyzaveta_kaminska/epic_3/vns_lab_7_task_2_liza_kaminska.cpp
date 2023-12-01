#include <iostream>
#include <string>

using namespace std;

struct JapaneseCalendar {
    string name;
    string colour;
};

JapaneseCalendar Japanese_year(int year) {
    string animal_names[12] = {"Rat", "Bull", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Cock", "Dog", "Pig"};
    string colours[5] = {"White", "Blue", "Green", "Red", "Yellow"};

    JapaneseCalendar result;

    int start = 1900;
    if (year < start) {
        cout << "Unknown name of year in Japanese calendar" << endl;
        result.name = "Unknown";
        result.colour = "Unknown";
        return result;
    }

    int animals_o = (year - start) % 12;
    int colour_o = (year - start) % 5;

    cout << "Your Japanese zodiac sign for the year is " << colours[colour_o] << " " << animal_names[animals_o] << endl;

    result.colour = colours[colour_o];
    result.name = animal_names[animals_o];

    return result;
}

string Zodiac_sign(string month) {
    string zodiac_signs[12] = {"Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn", "Aquarius", "Pisces"};
    string months[12] = {"April", "May", "June", "July", "August", "September", "October", "November", "December", "January", "February", "March"};

    int index = -1;

    for (int i = 0; i < 12; i++) {
        if(month == months[i]) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        cout << "Please write an existing month" << endl;
        return "Invalid.";
    }

    cout << "Your zodiac sign is " << zodiac_signs[index] << endl;

    return zodiac_signs[index];
}

int main() {
    int year;
    string month;

    cout << "Enter the year in Gregorian calendar: ";
    cin >> year;

    cout << "Enter the month: ";
    cin >> month;

    Japanese_year(year);
    Zodiac_sign(month);

    return 0;
}
