#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int x = 1, y; // 1. в коді використана як мінімум одна цілочисельна змінна
    const int a = 2, b = 3, c = 7; // 4. в коді використана як мінімум одна цілочисельна константа
    if (x < 2){
        y = pow(a, b-x) + c;
    }
    else if (x >= 2 && x <= 4){ // 5. в коді використані умовні оператори та розгалуження
        y = pow(b, c-x) + a;
    }
    else if (x > 4){
        y = pow(c, a-x) + b;
    }
    cout << "y = " << y;
    return 0;
}