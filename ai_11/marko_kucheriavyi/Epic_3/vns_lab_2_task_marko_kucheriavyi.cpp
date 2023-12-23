#include <iostream>
#include <cmath>
double factorial(int n)
{
    double factorial = 1;
    for (int i = 0; i < n; i++){
        factorial*=(i + 1);
    }
    return factorial;
}
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    double sum = 0;
    for (int i = 1; i < n +1; i++){
        sum += (factorial(i) / factorial(2 *i));
    }
    printf("sum = %.4f\n", sum);
    return 0;
}