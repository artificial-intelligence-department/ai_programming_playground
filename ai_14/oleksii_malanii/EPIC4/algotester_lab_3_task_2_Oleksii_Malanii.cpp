#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    cin >> n;
        vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
        vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int element = 0;
    for (int i = 0; i < n; ++i) {
        if (find(b.begin(), b.end(), a[i]) != b.end()) {
            element++;
        }
    }
     vector<int> com;
            com.insert(com.end(), a.begin(), a.end());
            com.insert(com.end(), b.begin(), b.end());
                sort(com.begin(), com.end());
                com.erase(unique(com.begin(), com.end()), com.end());
                    cout << element << endl;
                        cout << com.size() << endl;
    return 0;
}
