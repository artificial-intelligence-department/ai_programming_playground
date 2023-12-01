//
// Created by olehio-p on 10/28/2023.
//
#include <iostream>


int main(int argc, char const *argv[])
{
    int n = 2, m = 1;
    std::cout << "n++ * m: " << n++ * m << std::endl;

    n = 1, m = 1;
    std::cout << "n++ < m: " << (n++ < m) << std::endl;

    n = 2, m = 1;
    std::cout << "m-- > m: " << (m-- > m) << std::endl;

    return 0;
}
