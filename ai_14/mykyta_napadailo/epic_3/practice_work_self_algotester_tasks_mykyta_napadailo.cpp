#include <iostream>
using namespace std;

int main()
{
    const int bills[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    long long n, count = 0;
    cin >> n;
    for (int i = 8; i >= 0; i--)
    {
        while (n >= bills[i])
        {
            n -= bills[i];
            count++;
        }
    }
    cout << count;
    return 0;
}