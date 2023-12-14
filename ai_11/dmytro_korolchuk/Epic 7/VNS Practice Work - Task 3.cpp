#include <iostream>
using namespace std;

void Rax(double S, double litres, double amount){//функція для обчислення вартості поїздки
    litres = litres/100;//обчислюємо вартість
    double result;
    result = 2*S*litres*amount;
    cout<<result;//виводимо результат обчислень
}

int main(){
    double S, litres, amount;//задаємо тип змінних
    cout<<"Обчислення вартості поїздки на дачу і назад."<<endl;
    cout<<"Введіть початкові дані:"<<endl;
    cout<<"Відстань до дачі (км) ";
    cin>>S;//задаємо значення S
    cout<<"Витрата бензину (літрів на 100 км пробігу) ";
    cin>>litres;//задаємо значення litres
    cout<<"Ціна літра бензину (грн.) ";
    cin>>amount;//задаємо значення amount
    cout<<"Поїздка на дачу і назад обійдеться в ";
    Rax(S, litres, amount);//викликаємо функцію
}