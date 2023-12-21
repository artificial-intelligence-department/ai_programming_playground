#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int n,m;
    cout << "Enter n:";
    cin >> n;
    cout << "Enter m:";
    cin >> m;
    cout << '\n';
    cout << "Результат n++-m= " << n++-m <<endl;
    int x=m-->n;
    cout << x << endl;
    int t=n-->m;
    cout << t << endl;

    return 0;
}

