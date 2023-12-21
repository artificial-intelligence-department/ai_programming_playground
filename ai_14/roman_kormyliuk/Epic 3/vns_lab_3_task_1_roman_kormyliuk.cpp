#include <iostream>
#include <cmath>
using namespace std;
double factorial(int n){ // виводжу факторіал n
    double factorial = 1;
    for (int i = 0; i < n; i++){
        factorial*=(i + 1); 
    }
    return factorial; // рекурсія (повертає власне значення)
}
int main(){
    const double Eps = 0.0001, e = 2.71828;
    double  numbelement; // змінна для зберігання поточного елементу ряду
    for (double x = 0.1; x <= 1; x += 0.1){
        double SE = 0, SN = 0, Y; // SN- значення суми для заданого n; SE- значення суми для заданої точності; Y-точне значення функції.
        Y = pow(e, cos(x)) * cos(sin(x));
        for (int n = 0; n <= 20; n++){  // цикл для обчислення ряду тейлора для виразу
            SN += cos(n*x) / factorial(n);
        }
        int m = 0;
        numbelement = cos(m*x) / factorial(m); // знаходжу значення > eps
        while (abs(numbelement) > Eps){
            numbelement = cos(m*x) / factorial(m);
            SE += numbelement;
            m++;
        }
        cout << "x = " << x << " SN = " << SN << " SE = " << SE << " Y = " << Y << endl;
    }
    return 0;
}