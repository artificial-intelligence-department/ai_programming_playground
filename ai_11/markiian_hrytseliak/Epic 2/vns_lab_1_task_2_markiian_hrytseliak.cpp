#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout<<"Lab 1 task 2 Variant 7"<<endl;
    double m;
    double n;
    cout<<"Enter m:"<<endl;
    cin>>m;
    cout<<"Enter n:"<<endl;
    cin>>n;
    int result = m+--n;
    cout<<"The result of m+--n is:"<<result<<endl;
    cout<<"m++<++n"<<endl;
    if(m++<++n){
        cout<<"True"<<endl;
    } else{
    cout<<"False"<<endl;}
    cout<<"n--<--m"<<endl;
    if(n--<--m){
         cout<<"True"<<endl;
    } else
    cout<<"False"<<endl;
    

    return 0;
}