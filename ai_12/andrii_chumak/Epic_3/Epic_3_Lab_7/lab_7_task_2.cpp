#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

// Написати перевантажені функції й основну програму, що їх викликає
/*
а) для віднімання десяткових дробів;
б) для віднімання звичайних дробів.
*/

class DecimalFraction {
private:
    double value;

public:
    DecimalFraction(double val) : value(val) {}

    // Перевантажена функція віднімання для десяткових дробів
    DecimalFraction operator-(const DecimalFraction& other) const {
        return DecimalFraction(value - other.value);
    }

    // Вивід значення десяткового дробу
    void display() const {
        cout << value;
    }
};

class CommonFraction {
private:
    int numerator;
    int denominator;

public:
    CommonFraction(int num, int denom) : numerator(num), denominator(denom) {}

    // Перевантажена функція віднімання для звичайних дробів
    CommonFraction operator-(const CommonFraction& other) const {
        int resultNumerator = numerator * other.denominator - other.numerator * denominator;
        int resultDenominator = denominator * other.denominator;
        return CommonFraction(resultNumerator, resultDenominator);
    }

    // Вивід значення звичайного дробу
    void display() const {
        cout << numerator << "/" << denominator;
    }
};

int main() {
    // Віднімання десяткових дробів
    DecimalFraction decFraction1(5.5);
    DecimalFraction decFraction2(2.3);

    DecimalFraction resultDecimal = decFraction1 - decFraction2;

    cout << "Віднімання десяткових дробів: ";
    decFraction1.display();
    cout << " - ";
    decFraction2.display();
    cout << " = ";
    resultDecimal.display();
    cout << endl;

    // Віднімання звичайних дробів
    CommonFraction commonFraction1(3, 4);
    CommonFraction commonFraction2(1, 2);

    CommonFraction resultCommon = commonFraction1 - commonFraction2;

    cout << "Віднімання звичайних дробів: ";
    commonFraction1.display();
    cout << " - ";
    commonFraction2.display();
    cout << " = ";
    resultCommon.display();
    cout << endl;
}
