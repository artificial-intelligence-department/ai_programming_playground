// 5 Варіант
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    // додання дійсних змінних
    double a, b, c;
    // виведення тексту/ввід даних
    cout << "Ціна зошита (грн.) > ";
    cin >> a;
    cout << "Ціна обкладинок (грн.) > ";
    cin >> b;
    cout << "Кількість комплектів (грн.) > ";
    cin >> c;

    // обрахунок суми покупки
    double sum = c*(a+b);

    // виведення суми покупки
    cout << "Вартість покупки: " << sum << " грн\n";

    //Завдання 2

    // додання дійсних змінних
    double r,V,S;

    // додання константи
    const float pi = 3.14;

    // виведення тексту
    cout << "Введіть r";
    // введення даних
    cin >> r;
    
    // обрахунок площі та обєму
    S = 4*pi*pow(r,2);
    V = 0.75*pi*pow(r,3);

    // вивелення даних
    cout <<"Площа кругу:"<<S<<endl;
    cout <<"Обєм кругу:"<<V<<endl;

    return 0;
}