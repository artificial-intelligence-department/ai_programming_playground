#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cout<<"Enter n and m: ";
    cin>>n>>m;
    cout<<"n is: "<<n<<endl;
    cout<<"m is: "<<m<<endl;
    double first =n---m;
    cout<<"n---m is: "<<first<<endl;
    cout<<"n is: "<<n<<endl;
    cout<<"m is: "<<m<<endl;

    bool second = m--<n;
    cout<<"m--<n is: "<<second<<endl;
    cout<<"n is: "<<n<<endl;
    cout<<"m is: "<<m<<endl;
    
    double third = n++>m;
    cout<<second;
    cout<<"(n++>m) is: "<<third;

    return 0;
}
