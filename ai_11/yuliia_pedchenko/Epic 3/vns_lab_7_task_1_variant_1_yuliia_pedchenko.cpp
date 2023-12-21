#include <iostream>
#include <cstdarg>
using namespace std;
int sum(int n, ...) {
    int symma = 0;
    va_list vaargs;
    va_start(vaargs, n);
    for (int i = 0; i < n; i++) {
        int a = va_arg(vaargs, int);
        symma += a;

    }
    va_end(vaargs);
    return symma;

}

int main() {
    cout << sum(3, 4, 8, 2) << "\n";
    cout << sum(7, 57, 3, 28, 0, 5, 1337, 66) << "\n";
    cout << sum(11, 6, 4, 8, 11, 7, 54, 27, 55, 9, 32, 91);
}