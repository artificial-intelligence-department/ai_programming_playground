#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        v1.push_back(el);
    }
    auto firstPartition = partition(v1.begin(), v1.end(), [](int x)
    {
        return x % 3 == 0;
    });
    auto secondPartition = partition(firstPartition, v1.end(), [](int x)
    {
        return x % 3 == 1;
    });

    sort(v1.begin(), firstPartition);
    sort(firstPartition, secondPartition, greater<int>());
    sort(secondPartition, v1.end());

    auto rep = unique(v1.begin(), v1.end());
    v1.erase(rep, v1.end());

    cout << v1.size() << endl;
    for (auto a: v1)
    {
        cout << a << ' ';
    }
}