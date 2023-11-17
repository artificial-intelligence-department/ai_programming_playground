#include <iostream>
using namespace std;

int main()
{
    unsigned long n, suma = 0;
    unsigned long number[100000];
    cin >> n;

    for(int i=0; i< n; i++)
    {
        cin >> number[i];
        number[i] = number[i] - 1;
        if (number[i] >= 1)
        {
            suma = suma + number[i];    
        } 
    }
    std::cout << suma;
}
