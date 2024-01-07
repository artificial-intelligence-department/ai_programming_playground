#include <iostream>
#include <cmath>

using namespace std;

int main(){
    //variant 11
    double a,b,p,x = 1.25,y = 0.93, e = 2.71;
    a = ((1-y)*(pow((x+y), 2))/pow((x + 4), 3))/((pow(e, (2-x))) + ((pow(x, 3))+4));
    b = (1 + cos(y - 2))/(x * x + pow(sin(y - 2), 2));
    p = a/b;
    cout<<"The Result is: "<<p;
    return 0;
}