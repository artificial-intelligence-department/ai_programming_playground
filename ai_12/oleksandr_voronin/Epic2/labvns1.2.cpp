
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    int m, n;
    cout << "Type your number for m: \n";
    cin >> m;
    cout << "Type your number for n: \n";
    cin >> n;
    cout << " Answer 1: " << (++n) * (m++) <<endl;
    cout << " Answer 2: " << ((m++) < (n)) <<endl;
    cout << " Answer 3: " << ((n++) > (m)) <<endl;
    return 0;
}
