#include <iostream>
#include <cmath>

int main()
{
    int counter = 1;
    double total = 0;
    double limit = 0.0001;
    double sequence_member = 1; 

    while (sequence_member >= limit)
    {
        total += sequence_member;
        counter++;
        sequence_member = sequence_member * (std::pow(counter, counter)) / (std::pow(1 + counter, counter));   
    }

    std::cout << total << std::endl;
    return 0;
}
