// Торт від Толі
#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int c = a + b;

    while (a != 0 && b != 0) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }

    int v = a + b;

    cout << c - v << endl;

    return 0;
}
