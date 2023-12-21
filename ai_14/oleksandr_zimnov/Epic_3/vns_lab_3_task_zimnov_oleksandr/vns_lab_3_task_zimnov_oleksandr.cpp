#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int n=10;
    double k=(0.8-0.1)/n, sum_x=0, x_a=0, sum_y=0;
    for(int i=1; i<=n; i++){
        x_a+=k;
        sum_x+=pow(-1,i+1)*((pow(x_a,2*i))/(2*i*(2*i-1)));
        sum_y+=x_a*atan(x_a)-log(sqrt(1+pow(x_a,2)));
    }
    cout<<"a) Sum of number for n=10"<<endl;
    cout<<"x="<<sum_x<<endl;
    cout<<"y="<<sum_y<<endl;
    cout<<"b) Sum of number epsilon=0.0001"<<endl;
    cout<<"x="<<round(sum_x*10000)/10000<<endl;
    cout<<"y="<<round(sum_y*10000)/10000;
}
