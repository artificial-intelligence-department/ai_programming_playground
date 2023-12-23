#include <iostream> //додаємо потрібні бібліотеки
#include <cmath>
#include <string>

using namespace std; //зазначаємо робоче середовище

int main () {

string name; //позначаємо потрібні змінні
int amount, number, times, interest;
float sum1, sum2;
cout << "Enter your name:" << endl; //запрошуємо ввід даних від користувача
    cin >> name;
cout << "Enter the principal amount:" << endl;
    cin >> amount;
cout << "Enter the rate of interest (in percentage):" << endl;
    cin >> interest;
cout << "Enter the number of years:" << endl;
    cin >> number;
cout << "Enter the number of times interest is compounded per year:" << endl;
    cin >> times;

    int a = 10;

    sum1=amount*pow((1+(0.01*interest/times)), number*times) ; //подаємо формулу для обчислення складних відсотків
    sum2=sum1-amount;


    cout << "Hello, " << name << "!" << endl; //результуємо дані
    cout << "The compound interest for a principal of " << amount << " at a rate of " << interest << "% compounded " << times << " times a year for " << number << " years is: " << sum2 << ". The total amount after" << number << "years is: " << sum1 << endl;   
    return 0;
}