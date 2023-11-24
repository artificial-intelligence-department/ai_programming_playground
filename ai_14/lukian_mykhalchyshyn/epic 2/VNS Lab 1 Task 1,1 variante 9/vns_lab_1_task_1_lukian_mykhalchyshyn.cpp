#include <iostream>
#include <math.h>

int main()
{
    int a;
    float b, x, f, g, h, j, k;
    std::cout << "Enter a and b\n";
    std::cin >> a >> b;

    f = pow((a + b), 4);
    g = (pow(a, 4) + 4 * pow(a, 3) * b);
    h = 6 * pow(a, 2) * pow(b, 2);
    j = 4 * a * pow(b, 3);
    k = pow(b, 4);

    x = f - g / (h + j + k);
    x = x / pow(10,9);
    

    std::cout << "x= " << x << std::endl;

    return 0;
}