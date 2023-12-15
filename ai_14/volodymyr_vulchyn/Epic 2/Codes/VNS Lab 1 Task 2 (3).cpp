// 3) n-- > m++
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int m, n;
    cout << "Enter m: " << endl;
    cin >> m;
    cout << "Enter n: " << endl;
    cin >> n;
    --n;
    ++m;
//  n-- > m++ = означає що значення n зменшене на 1, має бути більшим за значення m збільшне на 1.

// Використовую оператор if, з умовою (n > m), якщо рівність справджується, то виводить cout нижче.
if (n > m) {
    cout << "The value of n > for the value of m " << (n > m) << endl;
// Використовую оператор else if, з умовою (n < m), за умови , якщо умова вище несправджується, і виводить cout нижче.
} else if (n < m) {
    cout << "Value of n < expression per value of m expression " << (n < m) << endl;
// Використовую вдруге оператор else if, з умовою (n = m), за умови , якщо обидві умови вище несправджуються, і виводить cout нижче.
} else if (n = m) {
    cout << "The value of n = the value of m. " << (n == m) << endl;
}

return 0;
}