#include<iostream>
using namespace std;


double pow(double number, int count)
{
    if (count == 1)
    {
        return number;
    }
    return number * pow(number,count - 1);
}
float pow_f(float number, int count)
{
    if (count == 1)
    {
        return number;
    }
    return number * pow(number,count - 1);
}

float numerator_f(float num1 ,float num2)
{
    return (pow_f(num1-num2, 3) - (pow_f(num1, 3) - 3 * num1 * pow_f(num2,2)));
}
float denominator_f(float num1, float num2)
{
    return (pow_f(num2, 3) -3 * pow_f(num1,2) * num2);
}
double numerator(double num1 ,double num2)
{
    return (pow(num1-num2, 3) - (pow(num1, 3) - 3 * num1 * pow(num2,2)));
}
double denominator(double num1, double num2)
{
    return (pow(num2, 3) -3 * pow(num1,2) * num2);
}
string check1(double m ,double n)
{
    return (m-- < n) ? "True" : "False";
}
string check2(double m ,double n)
{
    return (m++ > n) ? "True" : "False";
}
double difference(double m, double n)
{
    return n---m;
}

int main()
{
    double number1 = 1000, number2 =0.001, m, n;
    cout << "Enter m and n: ";
    cin >> m;
    cin >> n;
    cout << "Result of first(float) task: "<< numerator_f(number1, number2)/ denominator_f(number1,number2)<<endl;
    cout << "Result of first task: "<< numerator(number1, number2)/ denominator(number1,number2);
    cout << "\nTask two:\n1)"<< difference(m , n);
    cout << "\n2)"<< check1(m, n);
    cout << "\n3)"<< check2(m,n);
    return 0;
}
