#include <iostream>
#include<cmath>
using namespace std;


double pow(double number, int condition)
{
    if (condition == 1)
    {
        return number;
    }
    return number * pow(number, condition - 1);
}

double calculate_mac_sum(double number, int condition)
{
    double buff = (pow(number, 4 * condition + 1)) /(4 * condition + 1);
    if(condition == 1)
    {
        return buff;
    }
    return buff + calculate_mac_sum(number, condition - 1 );
}

double calculate_mac_sum(double number, double condition, int n = 1)
{
    double buff = (pow(number, 4 * n + 1)) /(4 * n + 1);
    if(condition > buff)
    {
        return 0;
    }
    return buff + calculate_mac_sum(number, condition, n = n + 1 );
}

int main() {
for (int i = 10; i < 80; i+=7)
{
    double n = i /100.00;
    cout<< "Argument X: "<< n<<endl;
    cout<< "Tailor formula by number monomials: "<<calculate_mac_sum(n,3)<<  endl;
    cout<< "Tailor formula by accuracity: "<< calculate_mac_sum(n, 0.0001)<< endl;
    cout<< "Y= "<< 0.25 * log((1+n)/(1-n))+ 0.5 * atan(n )<<endl;

}
return 0;
}
