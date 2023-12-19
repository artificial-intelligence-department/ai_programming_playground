#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> ammount(n);

    for (int i = 0; i < n; i++)
    {
        cin >> ammount[i];
    }

    auto minammout = min_element(ammount.begin(), ammount.end());
    auto maxammout = max_element(ammount.begin(), ammount.end());
    auto ammoutmin = *minammout;
    auto ammoutmax = *maxammout;
    auto time = ammoutmax - ammoutmin;

    cout << time;
}