#include <iostream>
using namespace std;
int main()
{
    int n;
    int k;
    int a;
    cin >> n >> k;
    a = k * 2 + n - k;
    if (a <= 26)
    {
        cout << "Yes";
    }
    else 
    {
        cout << "No";
    }
    

}