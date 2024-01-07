#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double z, x;
    for(x=-3; x<=3; x+=0.5)//z рахуватиметься з -3 до 3 через кожні 0,5
    {
        z=(cos(x)-1)/(x+1);
        if(x==-1)//так як знаменник не може дорівнювати 0, то значення -1 є неприпустимим
        {
            cout<<"When x="<<x<<" the answer is uncertain. The denominator can't be a 0\n";
        }
        else
        {
            cout<<"When x="<<x<<" z is equal to "<<z<<"\n";//виведення значень z в залежності від значень x
        }
    }

return 0;
}