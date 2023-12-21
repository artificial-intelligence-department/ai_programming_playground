#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int l = 1;
    int r = N;
    
    while (true) {
        if (l > r) {
            cout << l << " " << r << endl;
            cout << "Miss" << endl;
            break;
        } else if (l + 1 == r) {
            cout << l << " " << r << endl;
            cout << "Stopped" << endl;
            break;
        } else if (l == r) {
            cout << l << " " << r << endl;
            cout << "Collision" << endl;
            break;
        }

        l += a[l - 1];
        r -= a[r - 1];
    }

    return 0;
}
