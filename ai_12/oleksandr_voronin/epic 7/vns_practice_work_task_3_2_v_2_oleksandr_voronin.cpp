#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//Вимога 16. в коді використано параметри та аргументи функції
double FindVersts(long double km,long double x)
{
    return km * x;
}

int main(){
//Вимога 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    long double km,versts,x;

//Вимога 21. в коді використано оператори виведення та введення даних
    cout <<"Enter kilomiters"<<endl;
    cin >> km;

//Вимога 17. в коді використано математичні операції та математичні функції    
    x = 1000/1066.8; //знаходимо відношення кілометрів до верстви
    
    versts = FindVersts( km,x ); //Знаходимо верстви
    
    cout << fixed << setprecision(45) << versts;//задана максимальна точність після коми
}