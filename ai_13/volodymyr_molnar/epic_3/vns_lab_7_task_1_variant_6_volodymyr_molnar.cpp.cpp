#include <iostream>
#include <cstdarg>  
using namespace std;
int min(int count, ...) {
    va_list args; 
    va_start(args, count);  

    int min_val = numeric_limits<int>::max();  

    for (int i = 0; i < count; ++i) {
        int curent_val = va_arg(args, int);  
        if (curent_val < min_val) {
            min_val = curent_val;  
        }
    }

    va_end(args); 
    return min_val;
}

int main() {

    int res1 = min(5, 10, 7, 3, 15, 8);
    int res2 = min(10, 25, 30, 5, 8, 12, 18, 20, 6, 15, 9);
    int res3 = min(12, 3, 8, 17, 10, 22, 6, 14, 5, 12, 18, 7, 11);

    cout << "Min of 5 values: " << res1 << endl;
    cout << "Min of 10 values: " << res2 << endl;
    cout << "Min of 12 values: " << res3 << endl;

    return 0;
}
