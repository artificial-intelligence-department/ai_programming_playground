#include <iostream>
#include <cmath>

using namespace std;

int main(){

    double H, B, C;
    // скануєм вхідні дані
    cout << "Введіть розмір ящика:";
    cin >> H >> B >> C;
    // обчислюєм кількість болтів
    int result = H*B*C/0.000002;
    // виводим результат
    cout << result;




    return 0;

}