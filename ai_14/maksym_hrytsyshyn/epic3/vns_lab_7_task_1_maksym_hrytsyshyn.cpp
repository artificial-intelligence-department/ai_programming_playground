#include <iostream>
#include <cstdarg>
using namespace std;

int min(int n, ...) {

    va_list args;
    va_start(args, n);

    int min = va_arg(args, int);

    for (int i = 1; i < n; ++i) {
        int minTemp = va_arg(args, int);
        if (minTemp < min) {
            min = minTemp;
        }
    }

    va_end(args);

    return min;
}

int main()
{
    int array1[5];
    int array2[10];
    int array3[12];

    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) {
        cin >> array1[i];
    }

    cout << "Enter 10 numbers: ";
    for (int i = 0; i < 10; i++) {
        cin >> array2[i];
    }

    cout << "Enter 12 numbers: ";
    for (int i = 0; i < 12; i++) {
        cin >> array3[i];
    }

    int min1 = min(5, array1[0], array1[1], array1[2], array1[3], array1[4]);
    int min2 = min(10, array2[0], array2[1], array2[2], array2[3], array2[4], array2[5], array2[6], array2[7], array2[8], array2[9]);
    int min3 = min(12, array3[0], array3[1], array3[2], array3[3], array3[4], array3[5], array3[6], array3[7], array3[8], array3[9], array3[10], array3[11]);

    cout << "Min of 5 numbers: " << min1 << endl;
    cout << "Min of 10 numbers: " << min2 << endl;
    cout << "Min of 12 numbers: " << min3 << endl;

    return 0;
}
