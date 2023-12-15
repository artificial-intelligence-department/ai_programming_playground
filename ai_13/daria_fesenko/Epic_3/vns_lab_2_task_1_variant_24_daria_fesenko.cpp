#include <iostream>
#include <cmath>

 using namespace std;

int main () {
    int n;
    double sum;
     for (n=1; n<=9; ++n) {
        sum += exp(-sqrt(n));
     }
    cout << "Сума 9 членів ряду - " << sum << endl;

    return 0;
}