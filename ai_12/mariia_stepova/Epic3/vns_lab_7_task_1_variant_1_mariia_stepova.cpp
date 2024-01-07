#include <iostream>
#include <cmath>
#include <string>

using namespace std;


float sum(float * arr1, float * arr2, int n);


int main() 
{
    const int n = 12;
    
    float arr1[n] {1,2,3,4,5,6,7,8,9,10,11,12};
    float arr2[n] {12,11,10,9,8,7,6,5,4,3,2,1};
    
    cout << sum(arr1, arr2, 5) << endl;
    cout << sum(arr1, arr2, 10) << endl;
    cout << sum(arr1, arr2, 12) << endl;
    return 0;
}


float sum(float* arr1, float * arr2, int n)
{
    float res = 0;
    for(int i = 0; i < n; i++)
    {
        res += arr1[i] / arr2[i];
    }
    return res;
}