#include <iostream>
using namespace std;
int main(){
    float n;
    float m;
    cout<<"n = ";
    cin>>n;
    cout<<"m = ";
    cin>>m;
    float a = m+--n;
    bool b = m++<++n;
    bool c = n--<--m;
    cout<<"Results are :\n"<<a<<endl<<b<<endl<<c<<endl;
    
    return 0;


}