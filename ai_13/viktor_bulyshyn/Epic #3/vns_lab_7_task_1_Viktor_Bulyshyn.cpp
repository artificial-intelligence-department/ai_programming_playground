#include <iostream>
#include <stdarg.h>
#include <bitset> // Друг сказав так буде легше

using namespace std;

// перетворення чисел з двійкової системи числення в трійкову
void trans(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        int binaryNumber = va_arg(args, int);
// перетворення чисел з двійкової в трійкову 
        cout << "Binary: " << bitset<8>(binaryNumber) << ", Ternary: ";

        while (binaryNumber > 0) {

            int remainder = binaryNumber % 3;

            cout << remainder;

            binaryNumber /= 3;
        }
        cout << endl;
    }

    va_end(args);
}

int main() {

    trans(3, 3, 6, 7);

    return 0;
}