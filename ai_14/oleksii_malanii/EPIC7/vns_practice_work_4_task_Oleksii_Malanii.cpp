#include <iostream>
using namespace std;
int main() {
    int n;
    int sum = 0;
    cout << "Enter the number of series members: ";
    cin >> n;
    for (int i = 1, count = 0; count < n; i += 2, ++count) {
        sum += i;
    }
    cout << "Sum of first " << n << " Odd numbers: " << sum << endl;
    return 0;
}
