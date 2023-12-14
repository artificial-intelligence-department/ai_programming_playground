#include<iostream>
#include<cmath>
using namespace std;

double calculate_function(double x)
{
    double z = abs(x) + pow(x, 2);
    return z * pow(sin(2 + x), 2) / (2 + x);
}

void print_results(double start_x, double end_x, double step)
{
    cout << "        sin(2 + x)^2" << endl << "y = z * -------------" << endl << "            2 + x" << endl;
    for(start_x; start_x <= end_x; start_x += step)
    {
        cout << "x = " << start_x << ":" << endl;
        cout << "y = " << calculate_function(start_x) << endl;
    }
}

int main()
{
    double start_x = -2.5;
    double end_x = 2;
    double step = 0.5;
    print_results(start_x, end_x, step);
}