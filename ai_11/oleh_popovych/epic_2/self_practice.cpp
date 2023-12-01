//
// Created by olehio-h on 10/31/2023.
//
#include <iostream>


bool is_happy_number(int);
unsigned long long binpow(unsigned long long, int);

int main(int argc, char const *argv[])
{
    int lower, upper;
    std::cin >> lower >> upper;

    unsigned long long sum = 0;
    for(int i = lower; i <= upper; i++)
    {
        if(is_happy_number(i))
        {
            sum += binpow(i, i);
        }
    }
    std::cout << sum % 1234567891<< std::endl;
    return 0;
}


bool is_happy_number(int number) {
    int remains;
    bool is_happy = true;
    while(number != 0) {
        remains = number % 10;
        if(!(remains == 4 || remains == 7))
        {
            is_happy = false;
            break;
        }
        number /= 10;
    }
    return is_happy;
}

unsigned long long binpow(unsigned long long a, int n) {
    unsigned long long res = 1;
    while(n)
    {
        if (n & 1)
            res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}
