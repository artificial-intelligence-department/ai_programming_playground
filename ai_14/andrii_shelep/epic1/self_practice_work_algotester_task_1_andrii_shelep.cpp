#include <iostream>

using namespace std;
//задача з алготестеру "Депутатські гроші"
int main(){
    long int n, q500, q200, q100, q50, q20, q10, q5, q2, q1;
    cin >> n;

    q500= n / 500;
    n= n % 500;

    q200= n / 200;
    n= n % 200;

    q100= n / 100;
    n= n % 100;

    q50= n / 50;
    n= n % 50;

    q20= n / 20;
    n= n % 20;

    q10= n / 10;
    n= n % 10;

    q5= n / 5;
    n= n % 5;

    q2= n / 2;
    n= n % 2;

    q1= n / 1;

    cout << q500+q200+q100+q50+q20+q10+q5+q2+q1 << endl;

    return 0;
}