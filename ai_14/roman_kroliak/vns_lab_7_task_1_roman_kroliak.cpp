#include <iostream>
#include <cstdarg>
using namespace std;
float mult(int a, ...){
    float prod = 1;
    va_list args;
    va_start(args, a);
    for (int i = 0; i < a; i++)
    {
        float value = va_arg(args, double);
        prod *= value;
    }
    va_end(args);
    return prod;
}
int main(){
    float res1 = mult(3, 1.0, 2.0, 3.0);
    cout << "Prod of 3: " << res1 << endl;
    float res2 = mult(7, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0);
    cout << "Prod of 7: " << res2 << endl;
    float res3 = mult(11, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0);
    cout << "Prod of 11: " << res3 << endl;
    return 0;
}