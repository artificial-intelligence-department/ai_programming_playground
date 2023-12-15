#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    unsigned long long n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int& el : arr) cin >> el;

    sort(arr.begin(), arr.end());
    
    auto last = unique(arr.begin(), arr.end());
    arr.erase(last, arr.end());
    
    k %= arr.size();
    rotate(arr.begin(), arr.begin() + k, arr.end());

    cout << arr.size() << endl;
    for (int el : arr) cout << el << " ";

    return 0;
}

