#include <iostream>

using namespace std;

short n,m;

int main()
{
    cin >> n >> m;
    
    if ((n*m)%2 == 0)
    {
        cout << "Dragon" << endl;
    }
    else
    {
        cout << "Imp" << endl;
    }

    return 0;
}
