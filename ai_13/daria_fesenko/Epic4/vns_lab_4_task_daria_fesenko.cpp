#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100;
int a[N], n;

void print(int k) {
    for (int i = k; i < k + n; i++) {
        cout << a[i % n] << " ";
    }
    cout << endl;
}

void sort_array() {
    sort(a, a + n);
}

void remove_even() {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            a[j++] = a[i];
        }
    }
    n = j;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }




    print(2);
    sort_array();
    remove_even();
    print(2);

    return 0;
}
