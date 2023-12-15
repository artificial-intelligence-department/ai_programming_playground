#include <iostream>
#include <cstdarg>

using namespace std;

int sum(int k, ...) {
    va_list args;
    va_start(args, k);

    int res = 0;
   

    int result = 0;
    for (int i = 0; i < k; ++i) {
        int current = va_arg(args, int);  
        if (i % 2 == 0) {
            res -= current;
        } else {
            res += current;
        }
    }

    va_end(args);  
    return res;
}

int main() {
    int result1 = sum(5, 1, 2, 3, 4, 5);
    int result2 = sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    int result3 = sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);

    
    cout << "Результат 1: " << result1 << endl;
    cout << "Результат 2: " << result2 << endl;
    cout << "Результат 3: " << result3 << endl;
    
    return 0;
}