#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    int n, m;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter m: ";
    cin>>m;
    cout<<"1) ++n*++m = "<<++n*++m<<endl;
    if(m++<n){
        cout<<"2) m++<n = true"<<endl;
    }else{
        cout<<"2) m++<n = false"<<endl;
    }
    if(n++>m){
        cout<<"3) n++>m = true"<<endl;
    }else{
        cout<<"3) n++>m = false"<<endl;
    }
    
}