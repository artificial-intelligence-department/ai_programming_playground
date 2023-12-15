#include <iostream>

using namespace std;

int main() {
    long long int n;
    cout << "Enter the amount of purchase" << endl;
    cin >> n;

    int denominations[9] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int count = 0;

    for (int i = 0; i < 9; i++) {
        count += n / denominations[i];
        n %= denominations[i];
    }

    cout << "Minimum number of bills for purchase: " << count << endl;

    return 0;
}


