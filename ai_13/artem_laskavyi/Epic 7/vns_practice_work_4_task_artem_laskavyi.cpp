#include <iostream>
#include <cmath>
using namespace std;

int Powers(int base, int exp){
    if (exp == 0) {
        return 1;
    } else {
        return base * Powers(base, exp - 1);
    }
}

int main() {

    for (int exp = 0; exp <= 10; ++exp) {
        cout << "2 to the power of " << exp << " equals " << Powers(2, exp) << endl; 
    }

    return 0;
}
