#include <iostream>
#include <cstdarg>
#include <cmath>

using namespace std;

int binaryToDecimal(int binaryNumber) { //binary to decimal
    int decimalNumber = 0, i = 0, buff;
    while (binaryNumber != 0) {
        buff = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += buff * pow(2, i);
        ++i;
    }
    return decimalNumber;
}

int decimalToTernary(int decimalNumber) { //decimal to ternary
    int ternaryNumber = 0, i = 1, remainder;
    while (decimalNumber != 0) {
        remainder = decimalNumber % 3;
        decimalNumber /= 3;
        ternaryNumber += remainder * i;
        i *= 10;
    }
    return ternaryNumber;
}

int fun(int n, ...); 
int funlog(int n, ...); 

int main() {
    fun(3, 101, 110, 11);
    fun(6, 101, 110, 11, 111, 1001, 10);
    fun(7, 101, 110, 11, 111, 1001, 10, 1);
    funlog(2, 10, 3);

    return 0;
}

int fun(int n, ...) { // binary to ternary
    va_list nums;
    va_start(nums, n);
    for (int i = 0; i < n; i++) {
        int buff = va_arg(nums, int);
        cout << "Binary: " << buff << ", Ternary: " << decimalToTernary(binaryToDecimal(buff)) << endl;
    }
    va_end(nums);
    return 0;
}

int funlog(int n2, ...) { // log(e), log(10)
    va_list nums2;
    va_start(nums2, n2);
    for (int i = 0; i < n2; i++) {
        int buff2 = va_arg(nums2, int);
        cout << "Variable: " << buff2 << ", log(e): " << log(buff2) << ", log(10): " << log10(buff2) << endl;
    }
    va_end(nums2);
    return 0;
}
