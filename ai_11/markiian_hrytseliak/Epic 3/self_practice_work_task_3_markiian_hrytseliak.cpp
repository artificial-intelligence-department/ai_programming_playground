#include <iostream>

using namespace std;

int sumTo(int value)
{
    int sum=0;
    for(int i=1; i<=value; i++)
    {
        sum+=i;
    }
    return sum;
}

int main()
{
    cout<<sumTo(10);
    return 0;
}