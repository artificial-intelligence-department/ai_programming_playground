#include <iostream>

int main ()
{
    int m, n, result_1;
    std::cout <<"enter m: ";
        std::cin >> m;
        std::cout <<"enter n: ";
        std::cin >> n;

        result_1= --m-++n; 
        std:: cout << "result_1: " << result_1 << std::endl;

        m*n < n++ ? std::cout << "statement 1 is true\n" : std::cout << "statement 1 is false\n";
        n-- > m++ ? std::cout << "statement 2 is true\n" : std::cout << "statement 2 is false\n";

        return 0;
}
