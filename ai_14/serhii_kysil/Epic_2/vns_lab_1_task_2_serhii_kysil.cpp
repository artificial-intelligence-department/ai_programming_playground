#include <iostream>
using namespace std;
int main() {
    int n, m, x;
    string y, z;
    cout << "Enter n: ";
    cin >> n;
    cout<<"Enter m: ";
    cin>>m;
    x=n---m;
    if (m-- < n) { 
        y="true"; 
    }   else {
        y="false";
    }
    if (n++ > m) {
        z="true"; 
    }   else {
        z="false";
    }
    cout<<"Equality1 = " << x <<endl;
    cout<<"Inequality2 = " << y <<endl;
    cout<<"Inequality3 = " << z;
    return 0;
}