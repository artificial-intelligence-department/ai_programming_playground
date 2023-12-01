#include <iostream>
#include <cmath>

using namespace std;

void overload(int number, int n);

void overload(int number, int n)
{
int res=pow(number, n);
cout<<res;
}
void overload(double number, double n)
{
double res = pow(number, (1/n));
cout<<res;
}

int main(){
double a,n1;
int b,n;
cin>>a>>n1;
cout<<"Корінь нго степення:";
overload(a ,n1);
cout<<'\n';
cin>>b>>n;
cout<<"Ний степінь числа:";
overload(b ,n);
cout<<'\n';
    return 0;
}