#include <iostream>    // Підключення бібліотеки для введення і виведення даних
using namespace std;   // Використання імен простору std

int main() {
    double VOLT, OM; // Оголошення змінних типу double
    double a = 2.1265123, b = 3.1116743, c = 1.5224222, d = 4.346372;
    // Оголошення та ініціалізація змінних

    cout << "Enter volts(>36): "<<endl; // Вивід  тексту про введення вольт
    cin >> VOLT; // Ввід значення змінної VOLT

    if (VOLT<=36)  // Перевірка чи VOlT менше або рівне за 36
    {
        cout<<"Wrong input!"<<endl;
        return 0;  // Закінчення програми при некоректному вводі
    }

    cout << "Enter ohms(>1500): "<<endl;
    cin >> OM;

    if (OM<=1500)   // Перевірка чи OM менше або рівне за 1500
    {
        cout<<"Wrong input!"<<endl;
        return 0;   // Закінчення програми при некоректному вводі
    }
    
    double AM;      // Оголошення змінної AM
    AM = VOLT / OM; // Обчислення щначення змінної AM

    cout <<AM<< " Amperes" << endl; // Вивід значення AM

    cout<<endl;


    cout<<"Enter a value of a, b, c, d: "<<endl; 
    cin>>a>>b>>c>>d; // Введення значень змінних

    double difference = (a * b) - (c * d); 
    // Оголошення змінної difference, та обчислення її значення за допомогою різниці добутків

    cout << "Difference between (a * b) and (c * d): " << difference << endl; 
    // Вивід значенння змінної difference

    return 0; // Закінчення програми
}