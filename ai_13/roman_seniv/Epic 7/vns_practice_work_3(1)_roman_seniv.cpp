#include <iostream>

using namespace std;

 
int main() {
    double s, t;

    cout << "Enter distance (in kilometers): ";
    cin >> s;

    cout << "Enter time (in hours): ";
    cin >> t;
 
    if (t != 0) {
        double v = s / t;
        cout << "Runner's speed: " << v << " km/h" << endl;
    }

    return 0;
}
