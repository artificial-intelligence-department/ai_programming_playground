#include<iostream>
using namespace std;
double Calculate(double number1, double number2, char action)
{
    double result;
    switch(action)
    {
        case '+': 
            result = number1 + number2;
            break;
        case '-':
            result = number1 - number2;
            break;
        case '*':
            result = number1 * number2;
            break;
        case '/':
            result = number1 / number2;
            break;
    }
    return result;
}
int main()
{
    double number1;
    double number2;
    char action;
    cout << "Enter first number: ";
    cin >> number1;
    while (action != '+' && action != '-' && action != '*' && action != '/')
    {
        cout << "Enter action: ";
        cin >> action;
    } 
    if(action == '/')
    {
        while(number2 == 0)
        {
        cout << "Enter second number: ";
        cin >> number2;
        }
    }
    else
    {
        cout << "Enter second number: ";
        cin >> number2;
    }
    cout << number1 << " " << action << " " << number2 << " = " << Calculate(number1, number2, action) << endl;
}