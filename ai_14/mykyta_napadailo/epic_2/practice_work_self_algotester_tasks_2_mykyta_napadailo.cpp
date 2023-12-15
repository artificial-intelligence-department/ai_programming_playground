#include <iostream>
using namespace std;

int main()
{
    long packs, max = 0;
    cin >> packs;
    long cookies[packs];
    for (int i = 0; i < packs; i++)
    {
        cin >> cookies[i];
        max += cookies[i] - 1;
    }
    cout << max;
}
