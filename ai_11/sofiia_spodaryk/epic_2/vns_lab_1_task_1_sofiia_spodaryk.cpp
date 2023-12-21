#include <iostream>

using namespace std;
int main()
{
    float a = 1000;
    float b = 0.0001;
    float result = (pow(a - b, 3) - pow(a, 3) + 3 * a * (pow(b, 2))) / (pow(b, 3) - 3 * (pow(a, 2)) * b);
    cout << "Ваш результат = " << result;

    return 0;
}
