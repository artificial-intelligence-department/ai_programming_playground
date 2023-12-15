#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int sum,num = 0;
    for(;num<200;num+=3)
    {
        sum+=num;
    }
    cout << sum;
}