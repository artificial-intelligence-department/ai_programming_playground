#include <iostream>
using namespace std;

int main() {
    long sum=0;
    long n;
    cin >>n;
    long a[n];
       for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += (a[i] - 1);
           // sum += a[i];

    }
    cout<<sum;
   // cout<<(sum-n);
    return 0;
}


