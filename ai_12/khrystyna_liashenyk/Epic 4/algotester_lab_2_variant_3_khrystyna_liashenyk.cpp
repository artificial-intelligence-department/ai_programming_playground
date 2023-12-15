#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;

   int array[n];
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    int dr1 = 1;
    int dr2 = n;

    while (true) {
        if (dr1 == dr2) {
            cout << dr1 << " " << dr2 << endl;
            cout << "Collision";
            break;
        } else if (dr1 > dr2) {
            cout << dr1 << " " << dr2 << endl;
            cout << "Miss";
            break;
        } else if ((dr1 == dr2 - 1) || (dr1 + 1 == dr2)) {
            cout << dr1 << " " << dr2 << endl;
            cout << "Stopped";
            break;
        }

        dr1 += array[dr1 - 1];
        dr2 -= array[dr2 - 1];
    }

    return 0;
}

