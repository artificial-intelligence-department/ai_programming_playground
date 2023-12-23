#include <iostream>
using namespace std;

int main()
{
    // Введення даних
    cout << "Введіть назву товару: ";
    string name;
    cin >> name;
    cout << "Введіть нижню межу ваги(у грамах): ";
    int minWeight;
    cin >> minWeight;
    if(minWeight < 0)
    {
        cout << "Некоректні введені дані. Будь ласка, перевірте введені значення.";
        return -1; // Помилка введення
    }
    cout << "Введіть верхню межу ваги(у грамах): ";
    int maxWeight;
    cin >> maxWeight;
    if(maxWeight < 0 || maxWeight < minWeight)
    {
        cout << "Некоректні введені дані. Будь ласка, перевірте введені значення.";
        return -1; // Помилка введення
    }
    cout << "Введіть крок ваги(у грамах): ";
    int step;
    cin >> step;
    if(step < 0)
    {
        cout << "Некоректні введені дані. Будь ласка, перевірте введені значення.";
        return -1; // Помилка введення
    }
    cout << "Введіть ціну за " << step << " г: ";
    int price;
    cin >> price;

    if (price < 0)
    {
        cout << "Некоректні введені дані. Будь ласка, перевірте введені значення.";
        return -1; // Помилка введення
    }

    for(int i = 0; i <= (maxWeight-minWeight)/step; i++)
    {
        double sum = price*(minWeight+i*step)/step; // Розрахунок суми
        if(minWeight+i*step != maxWeight)
        cout << "Вага: " << minWeight+i*step << " г, Ціна: " << sum << " грн" << endl; // Виведення результату
    }
    // Розрахунок для максимальної ваги
    double sum = price*maxWeight/step;
    cout << "Вага: " << maxWeight << " г, Ціна: " << sum << " грн";
}