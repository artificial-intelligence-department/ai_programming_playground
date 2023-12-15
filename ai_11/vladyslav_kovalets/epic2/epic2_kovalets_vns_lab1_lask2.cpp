#include <iostream> 

int main()
{
    int suma3[3];
    int  n, m;
    std::cin >> n;
    std::cin >> m;
    suma3[0] = n++ * m;
    suma3[1] = n++ < m;
    suma3[2] = m-- > n;
    std::cout << suma3[0]<< std::endl << suma3[1] << std::endl << suma3[2];
    return 0;
}
