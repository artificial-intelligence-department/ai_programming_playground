#include <iostream>
using namespace std;

int main()
{
    long int n;
    cin >> n;
    int amount = 0;
    int groshi[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int i = 0;
    while (n != 0)
    {
        if (n >= groshi[i])
        {
            amount += n / groshi[i];
            n = n % groshi[i];
        }
        i++;
    }
    cout << amount;

    return 0;
}
