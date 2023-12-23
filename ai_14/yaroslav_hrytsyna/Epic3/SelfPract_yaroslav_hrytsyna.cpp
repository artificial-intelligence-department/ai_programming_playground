#include <iostream>
#include <cmath>

using namespace std;

int a11, a12, a21, a22;

int v(int a11,int a12,int a21,int a22){
    cout << ((a11*a22)-(a12*a21));
    return 0;
}

int main(){

    cout << "enter first row: ";
    cin >> a11 >> a12;
    cout << "enter second row: ";
    cin >> a21 >> a22;
    v(a11,a12,a21,a22);
}
