#include <iostream>
#include<math.h>
using namespace std;

int main()
{ 
    int n, m, a, b, c;
   
    cin>>n;
    cin>>m;
    
    a=m+--n;
    b=m++<++n;
    c=n--<--m;
   
    cout<<"1) m+--n = "<<a<<endl;
    cout<<"2) m++<++n = " <<b<<endl;
    cout<<"3) n--<--m = "<<c<<endl;
    return 0;

}