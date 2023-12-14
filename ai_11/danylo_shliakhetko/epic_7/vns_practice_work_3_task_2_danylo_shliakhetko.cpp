#include <iostream>
using namespace std;

int main()
{
    // Cтворюємо цілочисельні змінні cucumbers, tomatoes, salad
    int cucumumbers, tomatoes, salad;
    // Cтворюємо дійсні змінні priceСucumbers, priceTomatoes, priceSalad
    float priceCucumbers = 4, priceTomatoes = 5.5, priceSalad = 2.5;

    // Заповнюємо змінні cucumbers, tomatoes, salad з користувацького вводу
    cout << "Введіть кількість огірків: ";
    cin >> cucumumbers;
    cout << "Введіть кількість томатів: ";
    cin >> tomatoes;
    cout << "Введіть кількість пучків кропу: ";
    cin >> salad;

    // Рахуємо суму коштів
    float sum = cucumumbers * priceCucumbers + tomatoes * priceTomatoes + salad * priceSalad;

    // Виводимо повідомлення разом з результатом - об'ємом паралалепіпед
    cout << "Ви купили продуктів на " << sum << " грн.";
    return 0;
}