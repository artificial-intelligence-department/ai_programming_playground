#include <iostream>

using namespace std;

int main() {
    float n;
    float m;
    cout << "Enter number n: ";
    cin >> n;
    cout << "Enter number m: ";
    cin >> m;

    cout << "Case 1: n---m. Result is: " << n---m << endl;
    cout << "Case 2: m--<n. Result is: " << (m--<n) << endl;
    cout << "Case 3: n++>m. Result is: " << (n++>m) << endl;
}
