#include <iostream>
#include <cstdarg>
#include <vector>
using namespace std;

void decimalToOctal(int num, ...) {
    vector<int> octalDigits;

    va_list args;
    va_start(args, num);
    while (num > 0) {
        int octalDigit = num % 8;
        octalDigits.push_back(octalDigit);
        num /= 8;
    }

    cout << "Octal representation: ";
    for (int i = octalDigits.size() - 1; i >= 0; i--) {
        cout << octalDigits[i];
    }
    cout << endl;

    va_end(args);
}

int main() {
    decimalToOctal(10); 
    decimalToOctal(20, 30, 40);

    return 0;
}