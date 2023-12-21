#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int money[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    
    int N = 0;

    for(int i = 0; i < 9; i++)
    {
        while(n >= money[i])
        {
            n -= money[i];
            N++;
        }
    }

    cout << N << endl;

    return 0;
}