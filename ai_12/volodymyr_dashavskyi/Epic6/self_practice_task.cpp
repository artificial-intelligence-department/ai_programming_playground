#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;
    if (n < 0)
    {

        cout << "Error";
    }
    vector<long long> numbofcats(n);

    for (int i = 0; i < n; i++)
    {
        cin >> numbofcats[i];
    }

    auto mincoordinate = min_element(numbofcats.begin(), numbofcats.end());
    auto maxcoordinate = max_element(numbofcats.begin(), numbofcats.end());
    auto firstcoodrinate = *mincoordinate;
    auto lastcoordinate = *maxcoordinate;
    auto minimaltime = lastcoordinate - firstcoodrinate;

    cout << minimaltime;
}