#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter n and m" << endl;
    cin >> n >> m;
    
    int num1 = n---m;
    cout << "n --- m = " << num1 << endl;
    
    int num2 =m--<n;
    cout<<"m--n<n = "<<num2<<endl;
    
    int num3=n++>m;
    cout<<"n++>m = "<<num3<<endl;
    

    return 0;
}