#include <iostream>
using namespace std;
int main()
{
    cout<<"enter two numbers  with gap:\n";
    int n;
    int m;
    cin>>n>>m;
    cout<<(++n*++m)<<endl;
    cout<<(m++<n)<<endl;
    cout<<(n++>m);
    return 0;
}