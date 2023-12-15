#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    double eps = 0.0001;
    double sum_of_a_row = 0;
    double chlen_of_a_row = 1;
    double e = 2.71;
    int n = 1;

    do 
    {
        chlen_of_a_row = pow(e,n)*pow(100, -pow(n, 2));
        sum_of_a_row += chlen_of_a_row;
        n++;
    } 
    while (abs(chlen_of_a_row) > eps);

    cout << "Сума ряду з epsilon=0.0001 = " << sum_of_a_row << endl;

    return 0;
}
