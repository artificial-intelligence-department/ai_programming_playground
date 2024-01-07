#include <iostream>
using namespace std;
int main()
{

    unsigned int n;
    n != 0;

    int money[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

    int sum;
    sum = 0;

    cin >> n;

    for (int i = 0; i < 9; i++)
    {

        sum = sum + n / money[i];
        n = n % money[i];
    }

    cout << sum << endl;
    return 0;
}