#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    auto last = unique(a.begin(), a.end());
    a.resize(distance(a.begin(), last)); 

    k = k % a.size();

    rotate(a.begin(), a.begin() + k, a.end());

    cout << a.size() <<endl;
    for (int i = 0; i < a.size(); ++i) 
    {
        cout << a[i] << " ";
    }

    return 0;
}
