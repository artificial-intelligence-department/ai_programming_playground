#include <iostream>
#include <math.h>

using namespace std;

template <typename T>
void foo(T &a, T &b){
    
    auto numerator = pow(a + b, 3) - pow(a, 3);
    auto denominator = 3 * a * pow(b, 2) + pow(b, 3) + 3 * pow(a, 2) * b;

    if (denominator != 0) {
        auto result = numerator / denominator;
        cout << "Result: " << result << endl;
    } 
    else {
        cout << "Error: Division by zero" << endl;
    }
}

using namespace std;
int main() {
    const double a = 1000;
    const double b = 0.0001;

    const float a1 = 1000;
    const float b1 =0.0001;

    foo(a,b);
    foo(a1,b1);
    return 0;
}
