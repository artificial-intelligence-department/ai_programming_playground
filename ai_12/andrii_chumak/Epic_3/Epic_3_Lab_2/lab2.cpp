#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

/*
Використовуючи оператор циклу, знайти суму елементів, зазначених у
конкретному варіанті. Результат надрукувати, надавши відповідний
заголовком
*/
// Знайти суму ряду з точністю ε = 0.0001

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n = 1;
    double currentValue = (factorial(n)) / factorial(2 * n); // static_cast<double> метод для більшої точності результату
    double nextValue = currentValue * (1.0 / (4 * n + 2)); // рекурентна формула
    double epsilon = 0.0001;
    double sumValue = nextValue; 

    while (nextValue > epsilon) {
        n++;
        currentValue = currentValue * (1.0 / (4 * n - 2)); 
        nextValue = currentValue * (1.0 / (4 * n));   
        sumValue += nextValue;
    }

    cout << "Result: " << sumValue << endl;
}
