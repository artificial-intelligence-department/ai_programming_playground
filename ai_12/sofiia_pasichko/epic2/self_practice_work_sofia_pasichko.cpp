#include <iostream>
#include <cmath>
using namespace std;
int main () {
long long n[9], k[8], suma;
int i;
cin >> n[0];
int m[9]={500, 200, 100, 50, 20, 10, 5, 2, 1};

for (i=0; i < 8; ++i) {
    n[i+1]=n[i]%m[i];
    k[i]=n[i]/m[i];
}

suma = 0;
for (i=0; i < 8; ++i)
    suma += k[i];
    if (n[i-1]%2!=0) {
    suma=suma+1;
    }
cout << suma;
return 0;
}

