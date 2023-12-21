#include <iostream>

int main()
{
    int m;
    int n;

    std::cout << "Введіть n: ";
    std::cin >> n;
    std::cout << "Введіть m: ";
    std::cin >> m;

    int x = --m-++n;
    int g = m*n;
    int y = g<n++;
    int z = n-->m++;

    std::cout << "Результат: --m-++n: " << x <<std::endl;
    std::cout << "Результат: m*n<n++:  " << y <<std::endl;
    std::cout << "Результат: n-->m++: " << z <<std::endl;

    return 0;
   
}