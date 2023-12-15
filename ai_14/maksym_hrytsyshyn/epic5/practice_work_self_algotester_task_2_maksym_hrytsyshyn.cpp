#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n , m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    for(int i=0; i<m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    auto amin = a.begin();
    auto bmin = b.begin();

    int min = *amin + *bmin;

    cout << min << endl;
}
