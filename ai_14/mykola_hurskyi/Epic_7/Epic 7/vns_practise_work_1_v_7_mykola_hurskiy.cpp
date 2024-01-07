#include<iostream>      //Підключаю бібліотеку С++ і математичну бібліотеку
#include <cmath> 
using namespace std;    

int main(){               
double c = 9.1;     //ініціалізую змінні, а змінну с задаю значення сам, юо в уомі чітко не сказано
double a = 16.5;
double b = 3.4;
double x = 0.61;

double S;           //ініціалізація дійсної змінниої s
cout << "Calculating:" << endl;        //виведення стрічки 
c = (b * pow(x, 2) - c) / ((exp(a * x)) - 1);        //обчислюю с 
S =  ((pow(x, 3) * pow(tan(pow((x + b),2)), 2) + a) / (pow(x + b, 0.5))) * c;   //обчислюю s

cout << "Result 1: " << c << "Result 2: " << S;   //виведення результату 
    return 0;
}               