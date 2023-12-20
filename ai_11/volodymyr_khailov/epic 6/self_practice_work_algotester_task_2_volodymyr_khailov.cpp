// Розклад на прості множники
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> prime;
    int i = 2;
    while (i <= int(sqrt(n))) {
        if (n % i == 0) {
            prime.push_back(i);
            n = n / i;
        } else {
            i += 1;
        }
    }

    if (n > 1) {
        prime.push_back(n);
    }

    for (size_t j = 0; j < prime.size(); ++j) {
        cout << prime[j];
        if (j < prime.size() - 1) {
            cout << "*";
        }
    }

    return 0;
}