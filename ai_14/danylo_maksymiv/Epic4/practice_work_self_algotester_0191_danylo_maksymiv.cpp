#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int n,r;
    cin>>n;
    cin>>r; 
    float sqmax=pow(r,2);
    float c = sqmax/n;
    float res = sqrt(c);
    cout<<res;



}