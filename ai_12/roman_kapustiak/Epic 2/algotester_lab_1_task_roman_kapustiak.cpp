#include <iostream>

using namespace std;

int main()
{
    long long edge, nextEdge;
    int n = 4;
    
    if(!(cin >> edge))
    {
        cout << "Wrong input!\n";
        return 1;
    }

    if (edge <= 0)
    {
        cout << "ERROR\n";
        return 0;
    }

    while(n--)
    {
        if(!(cin >> nextEdge))
        {
            cout << "Wrong input!\n";
            return 1;
        }

        if (nextEdge <= 0)
        {
            cout << "ERROR\n";
            return 0;
        }
        if (edge < nextEdge)
        {
            cout << "LOSS\n";
            return 0;
        }
        edge = nextEdge;
    }

    cout << "WIN\n";

    return 0;
}
