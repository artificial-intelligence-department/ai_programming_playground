#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    for (int i = 21; i < 100; i++) {
        if (i % 3 == 0) {
            sum += i;
        }
    }
    cout << "sum: " << sum;
}
