#include <iostream>
using namespace std;
int main () {
long long n, i, suma;
cin >> n;
int *cookies = new int[n];
	for (int i=0; i < n; i++)
		cin >> cookies[i];
suma = 0;
for (i=0; i<n; ++i)
    suma += cookies[i];
    suma = suma-n;
cout << suma;
delete[] cookies;
return 0;
}

