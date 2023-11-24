#include <iostream>

int SumDigits(int num) {
    if (num < 10) 
        return num;
    else
        return num % 10 + SumDigits(num / 10);
    
}

int DigitalRoot(int num) {
    if (num < 10)
        return num;
    else 
        return DigitalRoot(SumDigits(num));
}

int main() {
    int num;
    std::cout << "Цифровий корінь числа: ";
    std::cin >> num;

    int n = DigitalRoot(num);
    std::cout << "Дорівнює : " << n << std::endl;

    return 0;
}
