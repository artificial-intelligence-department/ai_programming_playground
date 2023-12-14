#include <iostream>
using namespace std;

int main()
{
    // ініціалізація та введення початкових даних
    cout << "ВВедіть початкові дані: " << endl;

    double distance; // відстань до дачі
    cout << "Відстань до дачі (км) = ";
    cin >> distance;

    double consumption; // Витрата бензину (літрів на 100 км пробігу)
    cout << "Витрата бензину (літрів на 100 км пробігу) = ";
    cin >> consumption;

    double price; // Ціна літра бензину в грн
    cout << "Ціна літра бензину (грн) = ";
    cin >> price;

    // формула для обчислення вартості поїздки на дачу і назад
    double result = distance * consumption / 100 * price * 2; 
    // Виведення результату
    cout << "Поїздка на дачу і назад обійдеться в " << result << " грн" << endl;

    return 0;
}
