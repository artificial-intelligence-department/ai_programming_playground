#include <iostream>
using namespace std;
int main ()
{
    double S,h,b;
    cout<<"enter the length of the base of the triangle:"<<endl;
    cin>>b;
    cout<<"enter the length of the height of the triangle:"<<endl;
    cin>>h;
    S=(h*b)/2; //обчислення площі трикутника за допомогою формули
    cout<<"area of ​​the triangle:  "<<S<<" square cm"<<endl;
    return 0;
}
