#include <iostream>
using namespace std;

int main()
{
    float el; 
    float sum = 0;
    float average;
    int i, n;

    cout << "Number of elements: ";
    cin >> n;

    for(i = 1; i <= n; ++i)
    {
        cout << "Enter value of " << i << " element : ";
        cin >> el;
        
        if(el < 0)
        {
            goto label;
        } 
        sum += el;
    }
    
label:
    average = sum / (i - 1);
    cout << "\nAverage = " << average;
    return 0;
}