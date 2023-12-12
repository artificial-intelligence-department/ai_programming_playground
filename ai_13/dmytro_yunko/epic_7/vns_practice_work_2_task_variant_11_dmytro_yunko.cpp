#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    double a{1.0}, b{2}, x{1}, h{0.1};
    const double xM{3}, aM{5};

    for (double i = x; i < xM; i += h)
    {

        for (double j = a; j < aM; j += h)
        {
            cout << "x:" << i << "a:" << j << endl;
            
            if (x < b)
            {
                cout << "y = "  << sin(j * i + pow(b, j)) << endl;
                
            }
            else
            {

                cout << "y = " << cos(i*j - pow(b, j)) << endl;
                
            }
        }
    }

    return 0;
}
