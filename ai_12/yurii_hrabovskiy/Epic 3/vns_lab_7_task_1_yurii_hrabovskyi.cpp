#include <iostream>
#include <math.h>
#include <cstdarg>

using namespace std;

bool belongs_to_circle(double x, double y, double R)
{
    return(x*x+y*y<=R*R);
}


int belong(int count, ...)
{

    va_list list;
    va_start(list, count);
   
    int n=0;
    double x, y;
    double R;
    
    cout<<"Введіть радіус:  ";
    cin>>R;
    
    for(int arg=1; arg<=count; arg=arg+1)
    { 
        x=va_arg(list, double);
        arg=arg+1;
        y=va_arg(list, double);
        if (belongs_to_circle(x, y, R))
        {
            n=n+1;
        }
    }
    va_end(list);
    cout<<"Кількість точок, що належать даному колу, дорівнює:  "<<n<<endl<<endl;
    return n;
}


int main()
{       
    double x1, y1;
    cout<<"Введіть 2 координати для точки:  ";
    cin>>x1>>y1;
    belong(2, x1, y1);  // кількість параметрів 3
    
    double x2, y2, x3, y3, x4, y4;
    cout<<"Введіть по 2 координати для 3 точок:  ";
    cin>>x2>>y2>>x3>>y3>>x4>>y4;
    belong(6, x2, y2, x3, y3, x4, y4);  // кількість параметрів 7
    
    double x5, y5, x6, y6, x7, y7, x8, y8;
    cout<<"Введіть по 2 координати для 4 точок:  ";
    cin>>x5>>y5>>x6>>y6>>x7>>y7>>x8>>y8;
    belong(8, x5, y5, x6, y6, x7, y7, x8, y8);  // кількість параметрів 9
    
    return 0;
}