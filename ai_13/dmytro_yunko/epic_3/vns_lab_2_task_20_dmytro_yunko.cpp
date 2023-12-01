#include <math.h>
#include <iostream>


using namespace std;

int main()
{
    const double e {2.71828};
    double precision {0.0001};

    double sum {0};
    int i {1};
    double ar {pow(e,i)*pow(100, -pow(i, 2))};
    
    while (abs(ar)  > precision)
    {   
        ar = pow(e,i)*pow(100, -pow(i, 2));
        
        sum += ar;
        i++;
    }

    cout << sum <<endl;
    

    return 0;
}
