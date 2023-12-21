#include <iostream>
int main()
{
    long int A, B, C, D;
    std::cin >> A >> B >> C >> D;
    long int counter = 0;
    while (A > 0 || B > 0)
    {
        A -= C;
        B -= D;
        counter++;
    }
    std::cout << counter;
    
}
