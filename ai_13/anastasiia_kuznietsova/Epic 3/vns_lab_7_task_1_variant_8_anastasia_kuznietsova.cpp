#include <iostream>
using namespace std;

int max_value(int n, int k ...) 
{
    int* p = &k; 
    int max = *p;

    for (int i = 0; i<n; i++) 
    {
        int value = *(p + i);
        if (value > max) 
        {
            max = value;
        }
        *(++p);
    }

    return max;
}

int main() 
{
    int five = max_value(5, 3, 8, 15, 6, 2);
    int ten = max_value(10, 19, 8, 3, 17, 0, 2, 55, 31, 50, 30);
    int twelve = max_value(12, 44, 61, 21, 1, 5, 8, 3, 10, 92, 52, 17, 87);

    cout<<five<<"\n";
    cout<<ten<<"\n";
    cout<<twelve<<"\n";

    return 0;
}