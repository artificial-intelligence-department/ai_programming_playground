#include <iostream>
using namespace std;
int main() {
    for (double x = -4; x < 4; x += 0.5) {
        double a1, a2;
        if (x - 2 < 0)
            a1 = (x - 2) * -1;
        else
            a1 = (x - 2);
        if (x + 1 < 0)
            a2 = (x + 1) * -1;
        else
            a2 = (x + 1);
        double y = a1 + a2;
        cout << "x = " << x << "\t\ty = " << y << endl;
    }

    return 0;
}