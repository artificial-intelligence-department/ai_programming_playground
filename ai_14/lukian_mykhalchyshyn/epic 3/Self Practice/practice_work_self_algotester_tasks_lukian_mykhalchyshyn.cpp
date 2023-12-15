#include <iostream>

using namespace std;

int main()
{
    int N, C = 0;
    cin >> N;
    int V[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    for (int i = 0; i < 9; ++i)
    {
        while (N >= V[i])
        {
            N -= V[i];
            C += 1;
        }
    }
    cout << C;
}
