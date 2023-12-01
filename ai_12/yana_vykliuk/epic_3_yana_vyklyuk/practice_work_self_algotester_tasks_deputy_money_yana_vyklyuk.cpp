#include <iostream>

using namespace std;

long long n;
int c;

int main ()
{
    cin >> n;

    while(n >= 500)
    {
        n -= 500;
        c++;
    }

    while(n >= 200)
    {
        n -= 200;
        c++;
    }

    while (n >= 100)
    {
        n -= 100;
        c++;
    }

    while (n >= 50)
    {
        n -= 50;
        c++;
    }

    while (n >= 20)
    {
        n -= 20;
        c++;
    }

    while (n >= 10)
    {
        n -= 10;
        c++;
    }

    while (n >= 5)
    {
        n -= 5;
        c++;
    }

    while (n >= 2)
    {
        n -= 2;
        c++;
    }

    while (n >= 1)
    {
        n -= 1;
        c++;
    }
    
    cout << c << endl;

    return 0;
}
