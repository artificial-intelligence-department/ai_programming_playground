#include<iostream>
using namespace std;
int main(){
    const int first{8}, second{2}, third{30};
    int a, b,c, d;
    cout<<"Enter a number of pucks:  ";
    cin>>a;
    b=a*(first-1);
    c=b*2;
    d=c*(30-4);
    cout<<"Number of pucks for shift: "<<b<<endl;
    cout<<"Number of pucks for day: "<<c<<endl;
    cout<<"Number of pucks for month: "<<d<<endl;
}