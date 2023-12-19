#include <iostream>
using namespace std;

int main()
{
    long double KOL, ZM, DEN, MONTH;
    cout << "Введіть скільки шайб вироблятиме за годину > ";
    cin >> KOL;
    ZM = KOL * 7;
    DEN = ZM * 2;
    MONTH = DEN * 26;
    cout << "Виготовлена кількість деталей за зміну: " << ZM << endl;
    cout << "Виготовлена кількість деталей за день: " << DEN << endl;
    cout << "Виготовлена кількість деталей за місяць: " << MONTH << endl;
    return 0;
}
