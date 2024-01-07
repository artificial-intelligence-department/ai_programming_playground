#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    using namespace std;

    int n, k, b;
    cin >> n >> k;

    vector<int> uniqueSet;
    for (int i = 0; i < n; i++) {
        cin >> b;
        uniqueSet.push_back(b);
    }

    sort(uniqueSet.begin(), uniqueSet.end());
    auto x = unique(uniqueSet.begin(), uniqueSet.end());
    uniqueSet.erase(x,uniqueSet.end());
    if(k > uniqueSet.size()){
        k = k % uniqueSet.size();
    }


    rotate(uniqueSet.begin(), uniqueSet.begin() + k % uniqueSet.size(), uniqueSet.end());
    cout << uniqueSet.size() << endl;
    for (int j = 0; j < uniqueSet.size(); j++) {
        cout << uniqueSet[j] << " ";
    }

    return 0;
}
