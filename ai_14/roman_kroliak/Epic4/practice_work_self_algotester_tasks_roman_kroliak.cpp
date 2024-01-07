#include <iostream>
using namespace std;

int main(){
    int a[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    int size = sizeof(a)/sizeof(int);
    int n;
    cin >> n;
    int count = 0;
    for (int i = size-1; i >= 0; --i) {
        while(n - a[i] >= 0) {
            n -= a[i];
            count++;
        }
    }
    cout << count;
    return 0;
}