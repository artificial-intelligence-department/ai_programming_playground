#include <iostream>
#include <cmath>
using namespace std;

int digitsCount(int number)
{
    if (number < 0) number *= -1;
    int sum = 0;
    while (number != 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main()
{
    int number;
    cout << "Enter the number: ";
    cin >> number;
    cout << "Sum of digits in number " << number << " is " << digitsCount(number);
}