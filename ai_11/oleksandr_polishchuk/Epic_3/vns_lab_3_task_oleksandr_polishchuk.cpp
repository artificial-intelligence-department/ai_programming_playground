#include <iostream>
#include <cmath>

using namespace std;

double Factorial(int n)
{  
    double factorial=1.0;
    for (int i=1; i<=n; i++)
            {   
                factorial*=i;
            }
            return factorial;
}

int main() 
{   
    int m=0;
    double x=0.1, a=1, SN=0.0, SE=0.0, factorial=1.0, y=0;
    while (x >= 0.1 && x <= 1)
    {   
        y=(pow(M_E, x)+pow(M_E, (-x)))/2;
        cout << "X=" << x << "\t";
        
        for(int n=0; n<10; n++)
        {   
            factorial=Factorial(2*n);
            SN+=((pow(x, 2*n))/factorial);
        }
        
        cout << "SN=" << SN << "\t";
        
        while(a>0.0001)
        {   
            factorial=Factorial(2*m);
            a=pow(x, 2*m)/factorial;
            m++;
            SE+=a;
            
        }
        x+=(1-0.1)/10;
        
        cout << "SE=" << SE << "\t"; 
        cout << "Y=" << y << "\t"<< endl;
        a=1;
        m=0;
        SN = 0.0;
        SE = 0.0;
    }
    return 0;
}

