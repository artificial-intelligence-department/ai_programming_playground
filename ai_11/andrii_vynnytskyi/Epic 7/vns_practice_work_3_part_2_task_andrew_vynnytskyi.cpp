#include <iostream>
using namespace std;

int main()
{
    // Кількість годин у зміні
    const int hour_in_shift = 7;
    // Змінна для введення кількості деталей на годину
    double count;
    // Введення кількості деталей на годину від користувача
    cout<< " Enter count of details per hour: ";
    cin>> count;
    // Виведення кількості виготовлених деталей за одну зміну
    cout<<"Manufactured parts in one day with one shift: "<< count * hour_in_shift<<endl;
    // Виведення кількості виготовлених деталей за дві зміни
    cout<<" Manufactured parts in one day with two shifts: "<< count * hour_in_shift * 2<<endl;
    // Виведення кількості виготовлених деталей за місяць без вихідних
    cout<<" Manufactured parts in one month without weekends: "<< count * hour_in_shift * 26 <<endl;
    return 0;// Повертаємо 0 для позначення успішного виконання програми
}