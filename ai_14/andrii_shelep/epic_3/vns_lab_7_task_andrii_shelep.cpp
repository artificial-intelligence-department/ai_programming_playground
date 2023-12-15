#include <iostream>
#include <cmath>

using namespace std;

void bin_to_ternary(int num, ...) {
    int* ptr = &num;
    int n, value, bit, triple, digit, i, number;
    for (int j = 0; j < num; j++) {
        n = 0;
        ptr += 2;
        number = *ptr;
        value = 0;
        while (number != 0) {
            bit = number % 10;
            value += bit * pow(2, n);
            n++;
            number /= 10;
        }
        triple = 0;
        i = 0;
        while (value != 0) {
            digit = value % 3;
            triple += digit * pow(10, i);
            i++;
            value /= 3;
        }
        cout << triple << " ";
    }
    cout << endl;
}

int main() {
    bin_to_ternary(3, 101, 11, 1010);
    bin_to_ternary(6, 1011, 101010101, 10101, 11101, 101101, 10101);
    bin_to_ternary(7, 111, 10001, 10110, 1111, 11001, 101, 11);
    return 0;
}