#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a,a+N);
    auto it = unique(a, a + N);
    int newSize = distance(a, it); 
    rotate(a, a + K % newSize, a + newSize);
    cout << newSize << '\n';
    for (int i = 0; i < newSize; ++i) {
       cout << a[i] << ' ';
    }
    return 0;
}
