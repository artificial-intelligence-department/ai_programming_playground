#include <iostream>
using namespace std;

template <class T1, class T2>
T2 Sum(T1 a, T2 b)
{
    a++;
    b++;
    return a + b;
}

int main()
{
    cout<<""<<Sum(6, 6)<<endl;
    cout<<""<<Sum(18.3, 6.5)<<endl;
    cout<<""<<Sum(2, 4.5)<<endl;
    return 0;
}