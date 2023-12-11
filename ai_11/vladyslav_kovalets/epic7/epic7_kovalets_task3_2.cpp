#include <iostream>

int main()
{
    int km;
    double result;
    const double verst = 1066.8;

    std::cout << "Enter the km: ";
    std::cin >> km;
    result = km*1000/verst;

    std::cout << "This is a " << result << " verst.";
}
