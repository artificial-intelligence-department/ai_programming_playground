#include<iostream>
#include<cmath>

using namespace std;

int main() {
    double y;
    for (double x = -4.0; x <= 4; x += 0.5) {
        y = (2 * pow(x, 2)) - (5 * x) - 8;
        cout << y << endl;
        
    }
}