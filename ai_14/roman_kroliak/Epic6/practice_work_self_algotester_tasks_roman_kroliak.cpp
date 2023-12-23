#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int count = 0;
    int count_max = 0;
    for (int i : a) {
        if (i >= k) {
            count++;
            if (count >= count_max) count_max = count;
        }
        else count = 0;
    }
    cout << count_max;
    return 0;
}
