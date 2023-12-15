#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int sum = 0;
    int num = 0;
    while(num<200)
    {
        sum+=num;
        num+=3;
    }
    cout <<"The sum of positive integers that\nare "
            << "multiples of 3 and less than 200 is: \n"<< sum;

    return 0;
}