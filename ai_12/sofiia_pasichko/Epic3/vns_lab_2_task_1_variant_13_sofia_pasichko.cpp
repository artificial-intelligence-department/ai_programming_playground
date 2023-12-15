#include <iostream>
#include <cmath>
using namespace std;

int main() {
double n=1, epsylon=0.0001;
double suma=0;
double an;
an=1;
while (an>=epsylon) {
    an=an/(3*n+2);
    n++;
    suma=suma+an;
}
cout << suma;
return 0;
}

