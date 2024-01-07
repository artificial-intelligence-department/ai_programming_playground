#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a, b;
    double alp;
    // скануєм вхідні дані
    cout << "Введіть (через пропуск) довжини двох сторін (см) трикутника > ";
    cin >> a >> b;
    cout << "Введіть величину кута між сторонами трикутника > ";
    cin >> alp;
    // обчислюєм площу
    double result = a*b*sin(alp * M_PI/180)/2;
    // виводим площу
    cout << "Площа трикутника:" << result;


    return 0;
}