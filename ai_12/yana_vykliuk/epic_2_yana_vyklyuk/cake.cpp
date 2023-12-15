#include <iostream>
#include <math.h>

using namespace std;

short n, r;
float rmin;

int main()
{
    cin >> n >> r;
    
    if (n < 1 || n > 100 && r < 1 || r > 100)
    {
        return 0;
    }

    rmin = sqrt((pow(r,2)/n));

    cout << rmin << endl;

    return 0;
}
