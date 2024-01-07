#include <iostream>
#include <iomanip>
#include <sstream>


using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

bool leapisyear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

Date parseDate(const string& dateStr) {
    Date date;
    sscanf_s(dateStr.c_str(), "%d.%d.%d", &date.day, &date.month, &date.year);
    return date;
}

int days(const Date& date1, const Date& date2) {
    int days = date2.day;

    if (date2.month > 2 && leapisyear(date2.year)) {
        days += 29;
    }
    else {
        days += 28;
    }

    for (int i = 1; i < date2.month; i++) {
        if (i == 4 || i == 6 || i == 9 || i == 11) {
            days += 30;
        }
        else {
            days += 31;
        }
    }

    for (int i = 1970; i < date2.year; i++) {
        days += leapisyear(i) ? 366 : 365;
    }

    days -= date1.day;

    if (date1.month > 2 && leapisyear(date1.year)) {
        days -= 29;
    }
    else {
        days -= 28;
    }

    for (int i = 1; i < date1.month; i++) {
        if (i == 4 || i == 6 || i == 9 || i == 11) {
            days -= 30;
        }
        else {
            days -= 31;
        }
    }

    for (int i = 1970; i < date1.year; i++) {
        days -= leapisyear(i) ? 366 : 365;
    }

    return days;
}

int days(int n, const string dates[]) {

    int totalDays = 0;

    for (int i = 0; i < n - 1; i++) {
        totalDays += days(parseDate(dates[i]), parseDate(dates[i + 1]));
    }

    return totalDays;
}

int main() {

    string dates1[] = { "01.01.2023", "10.01.2023" };
    cout << days(2, dates1) << " days" << endl;
   
    string dates2[] = { "01.02.2023", "28.02.2023", "01.03.2023", "08.03.2023" };
    cout << days(4, dates2) << " days" << endl;

    string dates3[] = { "01.04.2023", "02.04.2023", "03.04.2023", "04.04.2023", "05.04.2023", "06.04.2023", "07.04.2023" };
    cout << days(7, dates3) << " days" << endl;

    return 0;
}