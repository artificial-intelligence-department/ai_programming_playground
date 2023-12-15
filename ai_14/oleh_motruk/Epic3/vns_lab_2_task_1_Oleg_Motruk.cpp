#include <iostream>
#include <cmath>

using namespace std;
int main() {
    double sum = 0.0;
    double a = 0.25;
    double e = 0.0001;
    int n = 1;
    for (n; abs(a) > e; n++){
        sum += a;
        a = 1.0 / ((3.0*n-2)*(3.0*n+1));
    }

    cout << sum << endl;

    return 0;
}
