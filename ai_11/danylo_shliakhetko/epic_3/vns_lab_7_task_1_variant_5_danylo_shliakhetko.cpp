#include <iostream>
#include <cstdarg>
using namespace std;


int sum(int count, ...)
{
    int *ptr = &count;
    int sum = 0;  

    for (int i = 0; i < count - 1; i++) {
        int a1 = *(ptr + 2), a2 = *(ptr + 4);
        sum += (i%2 ? -1 : 1) * a1 * a2;
        ptr += 2;
    }

    return sum;
}

int main()
{
    cout << "sum(5, 1, 2, 3, 4, 5) = " << sum(5, 1, 2, 3, 4, 5) << "\n";
    cout << "sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) = " << sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << "\n";
    cout << "sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) = " << sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) << "\n";
    return 0;
}