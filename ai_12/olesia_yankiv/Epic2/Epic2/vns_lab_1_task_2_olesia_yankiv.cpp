#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main ()
{
    int n,m;
    cout<<"Enter the number for n: "<<endl;
    cin>>n;
    
    cout<<"Enter the number for m: "<<endl;
    cin>>m;

    n--;
    int b = m+--n;
    cout<<"The 1 expresion equals: "<<b<<endl;

    m++;
    n++;
    int c = m++<++n;
    cout<<"The 2 expression equals: "<<c<<endl;

    n--;
    m--;
    int d = n--<--m;
    cout<<"The 3 expression equals: "<<d<<endl;
    
    return 0;
}