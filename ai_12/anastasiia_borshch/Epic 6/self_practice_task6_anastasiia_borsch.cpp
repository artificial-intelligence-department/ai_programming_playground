#include<iostream>

using namespace std;

int main()
{
    int n, m, i;
    cin >> n >> m;
    int a[n];
    int b[m];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    int minA = *min_element(a, a + n);
    int minB = *min_element(b, b + m);

    cout << minA + minB;

    return 0;
}