#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    double p,a,b, a_n, a_d, b_n, b_d;
    double x=1.25;
    double y=0.93;
    double e=M_E;
    //обчислення а
    a_n=(1-y)*((pow((x+y),2))/pow((x+4),3)); //чисельник a
    a_d=pow(e, (-(x-2)))+(pow(x,3)+4); //знаменник a
    a=a_n/a_d;
    //обчислення b
    b_n= 1+cos(y-2); //чисельник b
    b_d=pow(x,4/2)+pow(sin(y-2),2); //знаменник b
    b=b_n/b_d;
    //результат
    p=a/b;
    cout<<"the result of calculations is  "<<p;                                  
    return 0;
}
