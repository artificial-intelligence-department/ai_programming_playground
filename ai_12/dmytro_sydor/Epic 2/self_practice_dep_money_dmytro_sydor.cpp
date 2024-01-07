#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;
    int nominal[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < 9; i++)
    {
        count = count + n / nominal[i];
        n = n % nominal[i];
    }

    cout << count << endl;

    return 0;
}