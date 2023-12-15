#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int price_a, price_b;
    cin >> price_a >> price_b;

    int sum = ((a*price_a) + (b*price_b));
    cout << "the cost of your purchase is: " << sum << endl;

    return 0;
}