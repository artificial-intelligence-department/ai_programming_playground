#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    int m;
    (a[n-1]-a[1] < a[n-2]-a[0]) ? m = a[n-1]-a[1] : m = a[n-2]-a[0];
    if (n == 1) m = 0;
    cout << m;
    return 0;
}