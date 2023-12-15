#include <iostream>
#include <math.h>
using namespace std;

int main ()
{
int m, n, res;

cout << "Enter m and n: ";
cin >> m >> n;

res = --m-++n;   
cout << "The result is: " << res << endl;


if ((m*n) < (n++))
    {
        cout << "True\n";
    }
else
    {
        cout << "False\n";
    }
if ((n--)>(m++))
    {
        cout << "True";
    }
else 
{
    cout << "False";
}
return 0;
}