#include <iostream>
#include <cmath>
using namespace std;

float factorial(int n) // функція яка виконує роль факторіала
{
    float factorial = 1; 
    for (int i = 0; i < n; i++)
    {
        factorial *= (i + 1); 
    }
    return factorial;
}

int main()
{
    int n;
    cout << "Введіть n\n";
    cin >> n;
    float sum = 0;
    for (int i = 1; i < n; i++) // цикл розрахунку суми послідовності n
    { 
        sum += (factorial(i) / factorial(2 * i));
    }
    cout << sum;
    return 0;
}
