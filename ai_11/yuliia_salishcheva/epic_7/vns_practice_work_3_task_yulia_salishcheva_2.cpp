#include <iostream>
using namespace std;

int main() {
    //Декларація змінних і констант
    int shaybs_per_hour, count1DayShift = 0, count2DayShift = 0, count30Day = 0;
    const int hourCount1DayS = 8;
    const int preventionHour = 1;
    const int weekend = 4;
    const int daysOfmonth = 30;

    //Повідомлення для користувача, щоб той ввів дані(кількість шайб за годину)
    cout << "Enter count shaybs (in 1 hour): ";
    cin >> shaybs_per_hour;

    count1DayShift = shaybs_per_hour * (hourCount1DayS - preventionHour); // кількість деталей за 1 зміну в день
    count2DayShift = (shaybs_per_hour * (hourCount1DayS - preventionHour)) * 2;// кількість деталей за 2 зміни в день
    count30Day = (daysOfmonth - weekend) * count2DayShift;// кількість деталей за 2 зміни за місяць (з вихідними)

    //Виведення результатів
    cout << "The number of parts for 1 shift per day: " << count1DayShift << endl;
    cout << "The number of parts for 2 shifts per day: " << count2DayShift << endl;
    cout << "The number of parts for 2 shifts per month (including days off): " << count30Day << endl;
    return 0;
}
