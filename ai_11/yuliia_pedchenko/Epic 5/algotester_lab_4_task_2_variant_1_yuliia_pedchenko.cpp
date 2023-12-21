#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {

    vector<int> a;
    int N, K;

    cin >> N >> K;
    if (N < 1 || K < 1 || N > 1000 || K > 1000) return 0;
    
    for (int i = 0; i < N; i++) {
        int ai;
        cin >> ai;
        if (ai < 0 || ai > 100) return 0;
        a.push_back(ai);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    if ( K > a.size()) {
        while (K > a.size()) { 
            K -= a.size();
        }
        rotate(a.begin(), a.begin()+K, a.end());
    }
    else rotate(a.begin(), a.begin()+K, a.end());

    cout << a.size() << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}