// algotester 1051
// 47-й день року 

#include <iostream>

using namespace std;

// Функція перевіряє чи є рік високосним
bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

string find_47th_day(int year) {
    int days_in_february = is_leap_year(year) ? 29 : 28;

    int days_in_month[] = {0, 31, days_in_february, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int day = 47;
    int month = 1;

    // Пошук місяця та дня, коли 47-й день року буде досягнутий
    while (day > days_in_month[month]) {
        day -= days_in_month[month];
        month++;
    }

    // Формування рядка з датою у вигляді "dd.mm.yyyy"
    return (day < 10 ? "0" : "") + to_string(day) + "." + (month < 10 ? "0" : "") + to_string(month) + "." + to_string(year);
}

int main() {
    int year;
    
    cin >> year;

    cout << find_47th_day(year) << endl;

    return 0;
}
