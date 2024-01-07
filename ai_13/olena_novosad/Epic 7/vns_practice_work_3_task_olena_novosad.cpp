#include <iostream>// підключаю бібліотеку для вводу виводу
#include <stdio.h>//підключаю бібліотеку для вводу виводу
using namespace std;//використовую простір імен std
int main()
{
    //оголошуємо змінні типу float
    float distance;
    float consumption;
    float cost;
    float price;
    //запитуємо у користувача про необхідні дані та зчитуємо їх
    cout << "Enter start data:" << endl;
    cout << "Distance to the cottage>";
    cin >> distance;
    cout << "Fuel consumption for 100 km>";
    cin >> consumption;
    cout << "Cost of 1 l of fuel>";
    cin >> cost;

    price = (distance / 100) * consumption * cost * 2;//обраховую значення ціни за формулою
    printf ("Jorney to the cottage and back will cost: %.2f \n", price);//виводжу обраховане значення ціни

    double U, R;//оголошую змінні типу double
    cout << "Enter U and R to calculate I:" << endl;
    cin >> U >> R;//зчитуємо необхідні дані для обчислень
    double I = U / R;//обчислюємо силу струму
    cout << "Amperage is: " << I << " A";//виводимо значення
}