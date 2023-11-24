#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    int m_a, m_b, m_c;
    if(n % 2 == 0) {
        m_a = ( a[n/2 - 1] + a[n/2] ) /2;
        m_b = ( b[n/2 - 1] + b[n/2] ) / 2;
        m_c = ( c[n/2 - 1] + c[n/2] ) / 2;
    } else {
        m_a = a[n/2];
        m_b = b[n/2];
        m_c = c[n/2];
    }
    int m = 0;
    for (int i = 0; i < n; ++i) {
        m += abs(a[i]-m_a) + abs(b[i]-m_b) + abs(c[i]-m_c);
    }
    cout << m;
    return 0;
}
