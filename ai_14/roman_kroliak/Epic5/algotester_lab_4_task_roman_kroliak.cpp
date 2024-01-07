#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto partitionPointZero = partition(a, a + n, [](int num) { return num % 3 == 0; });
    auto partitionPointOne = partition(partitionPointZero, a + n, [](int num) { return num % 3 == 1; });
    sort(a, partitionPointZero);
    sort(partitionPointZero, partitionPointOne, greater<int>());
    sort(partitionPointOne, a + n);
    auto newEnd = unique(a, a + n);
    int newSize = distance(a, newEnd);
    cout << newSize << endl;
    for (auto i = a; i != newEnd; ++i) {
        cout << *i << " ";
    }
    return 0;
}