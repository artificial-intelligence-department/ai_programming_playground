#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    while (a!=0 && b!=0) {
        if (a>b) {
            a=a%b;
        }
        else b=b%a;
    }
    return a+b;
}

float transition(int a, int b)
{
    return a/b;
}

string transition(double a)
{
    int n=0;
    while (fmod(a, 10)!=0){
        a=a*10;
        n++;
    }
    int k, f, l, j;
    k=pow(10, n);
    f=gcd(a, k);
    l=a/f;
    j=k/f;

    return to_string(l) + "/" + to_string(j);

}

int main ()
{
    cout << transition(2.5) << endl;
    cout << transition(0.6) << endl;
    return 0;
}

