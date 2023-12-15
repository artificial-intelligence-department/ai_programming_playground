#include <iostream>  // Підключення бібліотеки для введення та виведення даних
using namespace std; // Використання простору імен std

// Функція, яку ми викликаємо і передаємо деякі значення. Функція повертає значення типу double
double Result(double price_b, double price_c, int amount){
    return (price_b + price_c) * amount; // Функція повертає деяке значення в головну функцію, звідки вона викликалась
}

int main(){
    double books_price, covers_price, res; // Оголошення зміних типу double 
    int amount;                            // Оголошення зміної типу int

    cout << "Enter the price of one book: ";  // Виведення на екран тексту
    cin >> books_price;                       // Вводимо значення через консоль і присвоюємо його до зміної
    cout << "Enter the price of one cover: "; // Виведення на екран тексту
    cin >> covers_price;                      // Вводимо значення через консоль і присвоюємо його до зміної
    cout << "Enter a number of sets: ";       // Виведення на екран тексту
    cin >> amount;                            // Вводимо значення через консоль і присвоюємо його до зміної

    res = Result(books_price, covers_price, amount); // Викликаємо функцію, передаючи їй деякі значення і повертаючи результат виконання функції
    cout << "The cost of your purchase is: " << res; // Виводимо на екран деякий текст і результат нашої програми

    return 0; // Повернення 0, що свідчить про успішне завершення програми
}