#include <iostream>

using namespace std;

int main() {
    int summ = 0;
    for (int a = 1; a < 200; a += 2) {
        summ += a;
    }

    cout << summ;

    return summ;
}
