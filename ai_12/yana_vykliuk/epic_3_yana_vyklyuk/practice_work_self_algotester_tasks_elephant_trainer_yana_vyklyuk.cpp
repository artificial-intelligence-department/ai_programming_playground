#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long xi, result;
vector <long long> x;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> xi;
        x.push_back(xi);
    }

    sort (x.begin(), x.end());
    result = x[n-1] - x[0];

    cout << result << endl;
    
    return 0;
}
