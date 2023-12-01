#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int maxCookies = 0;

    vector<int> cookies(n);
    for (int i = 0; i < n; ++i) {
        cin >> cookies[i];
    }

    
    sort(cookies.begin(), cookies.end());

    

    for (int i = 0; i < n - 1; ++i) {
        maxCookies += cookies[i];
    }

    cout << maxCookies << endl;

    return 0;
}