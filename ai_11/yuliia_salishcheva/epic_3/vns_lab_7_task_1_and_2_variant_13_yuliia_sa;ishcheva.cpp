//13. Написати функцію зі змінною кількістю параметрів для перекладу чисел з
//десяткової системи числення в трійкову.Написати викликаючу функцію
//main, що звертається до цієї функції не менше трьох разів з кількістю
//параметрів 3, 4, 7.

#include <iostream>
#include <cstdarg>
#include <vector>
using namespace std;

void decimalToTernary(int num, ...) {
    va_list args;
    va_start(args, num);

    cout << "Conversion of decimal numbers to ternary:" << endl;
    for (int i = 0; i < num; ++i) {

        int value = va_arg(args, int);
        vector<int> ternaryNumbers;

        cout << "Decimal number: " << value << " -> Ternary number: ";

        if (value == 0)
            cout << "0";
        else {
            bool NegativeNum = false;
            if (value < 0) {
                NegativeNum = true;
                value = -value;
            }

            while (value > 0) {
                int remainder = value % 3;
                ternaryNumbers.push_back(remainder);
                value /= 3;
            }

            if (NegativeNum) {
                cout << "-";
            }
            reverse(ternaryNumbers.begin(), ternaryNumbers.end());
            for (int num : ternaryNumbers) {
                cout << num;
            }
        }
        cout << endl;
    }

    va_end(args);
}


int main() {
    decimalToTernary(3, 1, 4, 2);
    cout << endl;
    decimalToTernary(4, 8, 9, 3, 7);
    cout << endl;
    decimalToTernary(7, 5, -6, 10, 11, 12, 13, 14);

    return 0;
}

//#include <iostream>
//#include <cmath>
//using namespace std;
//
//
//void decimalToFraction(double decimal, int& numerator, int& denominator) {
//    if (denominator != 0)
//    {
//        int precision = 0;
//        double fractionalPart = decimal - (int)(decimal);
//
//        while (fractionalPart > 0.0) {
//            fractionalPart *= 10.0;
//            fractionalPart -= (int)fractionalPart;
//            precision++;
//        }
//
//        numerator = (int)(decimal * pow(10, precision));
//        denominator = (int)(pow(10, precision));
//    }
//    else
//        cout << "error";
//}
//void decimalToDecimal(double& decimal, int& numerator, int& denominator) {
//    if (denominator != 0)
//        decimal = (double)numerator / (double)denominator;
//    else
//        cout << "error";
//}
//int main() {
//    double decimalNumber = 1.75;
//    int numerator, denominator;
//
//    decimalToFraction(decimalNumber, numerator, denominator);
//
//    cout << "1)Decimal : " << decimalNumber << " Fraction: " << numerator << '/' << denominator << endl;
//
//    double decimalNumber2;
//    int numerator2 = 1, denominator2 = 2;
//    decimalToDecimal(decimalNumber2, numerator2, denominator2);
//    cout << "\n2)Fraction: " << numerator2 << '/' << denominator2 << " Decimal : " << decimalNumber2 << endl;
//    return 0;
//}
