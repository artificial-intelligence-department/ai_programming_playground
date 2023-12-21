using namespace std;
#include<iostream>
#include<cmath>

const double ε = 0.0001;
const double a = 0.1;
const int b = 1;
const int k = 10;
const int n = 20;

int factorial_of(int number)
{
    int result = 1;
    for(int i = 0; i < number; i++)
    {
        result *= (i + 1);
    }
    return result;
}

double function_calculation(double x)
{
    return (exp(x)-exp(-x))/2;
}

double taylor_row_element_calculation(double x, int number)
{
    return pow(x, 2 * number + 1)/factorial_of(2 * number + 1);
}

void main_calculations()
{
    double step = (b - a)/k;
    for(double x = a; x <= b; x += step)
    {
        double sum_n = 0; 
        double sum_ε = 0;
        double y = function_calculation(x);
        for(int i = 0; i <= n/2; i++)
        {
            double taylor_row_element_calculations = taylor_row_element_calculation(x, i);
            sum_n += taylor_row_element_calculations;
            if(abs(taylor_row_element_calculations) > ε)
            {
                sum_ε += taylor_row_element_calculations;
            }
        }
        cout << "X = " << x << ",   SN = " << sum_n << ",   SE = " << sum_ε << ",   Y = " << y << endl;
    }  
}

int main()
{
    main_calculations();
}
