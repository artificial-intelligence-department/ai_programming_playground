#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> a;
    for (int i = 0; i < N; i++)
    {
        int el;
        cin >> el;
        a.push_back(el);
    }
    sort(a.begin(), a.end());
    auto last = unique(a.begin(), a.end());
    a.erase(last, a.end());
    K %= a.size();
    rotate(a.begin(), a.begin() + K, a.end());
    cout << a.size() << endl;
    for (auto element : a)
    {
        cout << element << ' ';
    }
}