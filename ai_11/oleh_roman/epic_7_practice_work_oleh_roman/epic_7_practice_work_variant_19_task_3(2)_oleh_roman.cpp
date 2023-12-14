#include <iostream>

int main(){
    int copybooks, pencils, PriceOfPencil, PriceOfCopybook;

    std::cout << "Enter price and amount of copybooks in set:" << std::endl;
    std::cin >> PriceOfCopybook >> copybooks;

    std::cout << "Enter price and amount of pencils in set:" << std::endl;
    std::cin >> PriceOfPencil >> pencils;

    std::cout << "Price of set will be equal to:" << PriceOfCopybook*copybooks + PriceOfPencil*pencils << std::endl;

    return 0;
}