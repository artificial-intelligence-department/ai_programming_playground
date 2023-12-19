#include <iostream>
#include <string>
#include <math.h>
//Вимога 4 - в коді використана як мінімум одна цілочисельна константа (для запису кількості голосних в прізвищі)
#define volves 4

using namespace std;

double yards_to_meters(float yards);

int main()
{
    //Вимога 2 - в коді використана як мінімум одна дійсна змінна (запис довжини поля в ярдах)
    float length_yards = 110;
    //Вимога 3 - в коді використана як мінімум одна дійсна з подвійною точністю змінна (для запису довжини плоя)
    double length_meters = yards_to_meters(length_yards);

    string surname;
    cout << "ENTER YOUR SURNAME: ";
    //Вимога 18 - в коді використано оператори виведення та введення даних(cin для введення прізвища)
    cin >> surname;

    double banner_length = surname.length() * volves * 0.8;
    double num_of_banners = length_meters / banner_length;
    
    cout << "LEFT TO RIGHT" << endl;

    string result_banners;
    //Вимога 1 - в коді використана як мінімум одна цілочисельна змінна (для ітерації по циклу)
    //Вимога 10 - в коді використаний for цикл (для запису певної кількості стрічок в нову стрічку)
    for (int i = 0; i < floor(num_of_banners); i++)
    {
        result_banners += surname;
    }

    double letters_per_meter = surname.length() / banner_length;

    int letters_start = (length_meters / 2 - 1.5) * letters_per_meter;
    int letters_end = (length_meters / 2 + 1.5) * letters_per_meter;
    //Вимога 18 - в коді використано оператори виведення та введення даних (cout для виведення результату)
    cout << "Letters in 3 center meters (left to right): " << result_banners.substr(letters_start, letters_end - letters_start + 1) << endl;
    
    cout << "RIGHT TO LEFT" << endl;

    string result_banners_2;
    //Вимога 15 - в коді використано математичні операції та математичні функції(floor() для округлення до меншого числа)
    for (int i = 0; i < floor(num_of_banners); i++)
    {
        result_banners_2 += surname;
    }

    double letters_per_meter_2 = surname.length() / banner_length;

    int letters_start_2 = (length_meters / 2 - 1.5) * letters_per_meter_2;
    int letters_end_2 = (length_meters / 2 + 1.5) * letters_per_meter_2;

    cout << "Letters in 3 center meters (right to left): " << result_banners_2.substr(letters_start_2, letters_end_2 - letters_start_2 + 1) << endl;

    return 0;
}
//Вимога 14 - в коді використано параметри та аргументи функції (функція параметром приймає дійсне число)
double yards_to_meters(float yards)
{
    yards *= 0.9144;

    return yards;
}