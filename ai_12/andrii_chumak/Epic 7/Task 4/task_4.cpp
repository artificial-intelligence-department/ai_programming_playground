#include <iostream>
#include <math.h>

using namespace std;

int main() {
    for(int i = 1; i <= 10; i++) {
        int square = pow(i, 2);
        cout << i << " = " << square << endl;
    }
}