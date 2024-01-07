#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double a = 10.2, b = 9.3, x = 2.4, c = 0.5;

    double answer = log(a + pow(x, 3)) + pow(sin(x / b), 2);

    double result = (exp(-c * x)) * ((x + sqrt(x + a)) / (x - sqrt(abs(x - b))));

    cout << "Результат K: " << answer << endl;
    cout << "Результат M: " << result << endl;

    
    return 0;
}
