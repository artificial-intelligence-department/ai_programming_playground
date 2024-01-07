//Варіант 22. Обчислення вартості покупки складається з
//декількох зошитів і такої ж кількості обкладинок до них.
//Нижче приведений вид екрану під час виконання програми, що
//рекомендується(дані, які вводяться користувачем, виділені
//напівжирним шрифтом).
//Обчислення вартості покупки.
//Введіть початкові дані :
//Ціна зошита(грн.) > 2.75
//Ціна обкладинок(грн.) > 0.5
//Кількість комплектів(грн.) > 7
//Вартість покупки : 15.45 грн.

#include <iostream>
using namespace std;

int main()
{
    //Декларація змінних
    double priceNotebook, priceEnvelope, countSets, purchasePrice = 0.0;

    //Повідомлення для користувача, щоб той ввів дані(про ціну зошита)
    cout << "Enter price notebook: ";
    cin >> priceNotebook;

    //Перевірка умови і виведення повідомлення в разі не правильного введення даних
    if (priceNotebook <= 2.75)
    {
        cerr << "You should enter price notebook > 2.75";
        return -1;
    }

    //Повідомлення для користувача, щоб той ввів дані(про обкладинки)
    cout << "Enter price envelope: ";
    cin >> priceEnvelope;

    //Перевірка умови і виведення повідомлення в разі не правильного введення даних
    if (priceEnvelope < 0.5)
    {
        cerr << "You should enter price envelope > 0.5";
        return -1;
    }

    //Повідомлення для користувача, щоб той ввів дані(кількість комплектів)
    cout << "Enter count sets: ";
    cin >> countSets;

    //Перевірка умови і виведення повідомлення в разі не правильного введення даних
    if (countSets < 7)
    {
        cerr << "You should enter count sets > 7";
        return -1;
    }

    purchasePrice = priceNotebook * countSets;//розрахунок ціни зошитів і додавання до загальної вартості
    purchasePrice += priceEnvelope * countSets;//розрахунок ціни обкладинок і додавання до загальної вартості

    //Виведення результатів
    cout << "Purchase price: " << purchasePrice << "grn" << endl;

}