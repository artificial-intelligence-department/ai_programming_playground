#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector <int> a(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    auto last = unique(a.begin(), a.end());
    a.erase(last, a.end());
    N = a.size();
    rotate(a.begin(), a.begin() + K % N, a.end());
    cout << N << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}