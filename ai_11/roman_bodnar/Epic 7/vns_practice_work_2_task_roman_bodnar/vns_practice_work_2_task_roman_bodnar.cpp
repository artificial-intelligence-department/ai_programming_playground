#include <iostream>

using namespace std;

int main() {

    int x;
    double y = 0;
    cout << "Number of x: ";
    cin >> x;
    for (int i = 1; i <= 10; i++) {
        y += pow(x,i)/i;
    }

    cout << "y" << " = " << y << endl;

    return 0;
}
