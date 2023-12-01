#include <iostream>
#include <vector>
using namespace std;

int main () {

long n;
long sum = 0;
cin >> n;

vector<long>a(n);

for (long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i]-1;
}
cout << sum;

    return 0;
}

