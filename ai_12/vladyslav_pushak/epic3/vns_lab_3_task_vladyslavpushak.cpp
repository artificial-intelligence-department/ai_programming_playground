#include <iostream>
#include <cmath>

double calculate(double var)
{
    return (1 + 2 * std::pow(var, 2)) * std::exp(std::pow(var, 2));
}

int main()
{
    double start = 0.1;
    double end = 1.0;
    int steps = 10; 
    int limit = 10;
    double precision = 0.0001;
    double increment = (end - start) / steps; 

    for (double var = start; var <= end; var += increment)
    {
        double sum_n = 1; 
        double sum_e = 1; 

        double term_n = 1; 
        double term_e = 1; 

        int counter = 1;

        while (counter <= limit)
        {
            term_n *= (2 * counter + 1) * std::pow(var, 2) / (counter * (counter + 1)); 
            sum_n += term_n;
            counter++;
        }

        counter = 1;
        while (term_e >= precision)
        {
            term_e *= (2 * counter + 1) * std::pow(var, 2) / (counter * (counter + 1)); 
            sum_e += term_e;
            counter++;
        }

        std::cout << "Variable:\t " << var << " Sum_N:\t " << sum_n << " Sum_E:\t " << sum_e << " Function:\t " << calculate(var) << "\n";
    }

    return 0;
}
