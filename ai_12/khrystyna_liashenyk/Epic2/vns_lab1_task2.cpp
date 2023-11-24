#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;
int main(){
    float m, n, a, b, c;

    cout <<  "Enter the number m ";
    cin >> m;
    cout <<  "Enter the number n ";
    cin >> n;
    a=m-++n;
    b=++m>--n;
    c=--n<++m;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    return 0;
}