#include <iostream>
#include <cmath> //підключаю заголовковий файл cmath, щоб мати змогу прауювати з математичними функціями

double Calculate(double x, double y) // функція для обчислення значення a
{
    double result = (sqrt(abs(x-1))-sqrt(y))/(1+pow(x,2)/2+pow(y,2)/4);  //використовую sqrt для кореня та функцію pow для підняття до степеня
    return result;
}

double Calculate(double x) // перевантажена функція для обчислення значення b
{
    double result = 1/tan(exp(x+3)); //реалізовую ctg (котангенс) через вираз 1/tg
    return result;
}

using namespace std;

int main(){
    double x, y;
    cout << "Введіть значення x: ";
    cin >> x; //вводимо значення x
    cout << "Введіть значення y: ";
    cin >> y;   //вводимо значення y

    double a = Calculate(x, y); //викликаємо функцію для обчислення значення a
    double b = Calculate(x); //викликаємо функцію для обчислення значення b

    cout << endl << "      Results" << endl; //виводимо результати
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}