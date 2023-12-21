#include <cstdarg>
#include <iostream>

using namespace std;

int sum(int n, ...)
{
    int s = 0;
    va_list array;

    va_start(array, n);


    for(int i = n;i!=0;i--)
    {
        int x = va_arg(array, int);
        s += x;
    }
    va_end(array);
    return s;
}
int main()
{
    cout<<sum(3,1,2,3)<<"\n";

    cout<<sum(7,1,2,3,4,5,6,7)<<"\n";

    cout<<sum(11,101,202,303,404,504,606,707,808,909,1010,1111)<<"\n";

    return 0;
}