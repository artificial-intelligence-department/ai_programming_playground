#include <iostream>
using namespace std;

double sum(double num1, double num2)
{
    return num1 + num2;
}

string sum(int numerator1, int denominator1, int numerator2, int denominator2)
{
    int denominator = denominator1*denominator2;
    int numerator = numerator1*denominator2 +numerator2*denominator1;
    return to_string(numerator) +'/' + to_string(denominator);
}

int main()
{
    cout<< "Decimal fraction: "<< sum(0.73, 0.96)<<endl;
    cout<< "Basic fraction:  "<< sum(7, 13, 8,23);
    return 0;

}
