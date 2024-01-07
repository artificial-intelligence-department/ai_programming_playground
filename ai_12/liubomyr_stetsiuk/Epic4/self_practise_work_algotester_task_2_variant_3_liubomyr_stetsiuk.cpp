#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    int x = 0;
    int z = 0;
    int j = 0;
    int i = 0;
    int p = 1;
    cin >> n;
    vector<int> number(n);
    for (int i = 0; i < number.size(); i++)
    {
        cin >> number[i];
    }
    x = 1;
    z = number.size();
    i = number[0];
    j = number[number.size() - 1];
    while (p != 0)
    {
        if (x == z - 1)
        {
            cout << x << " " << z << endl;
            cout << "Stopped" << endl;
            return 0;
        }
        if (x == z)
        {
            cout << x << " " << z << endl;
            cout << "Collision" << endl;
            return 0;
        }
        if (x > z)
        {
            cout << x << " " << z << endl;
            cout << "Miss" << endl;
            return 0;
        }
        x += number[i];
        z -= j;
        i = x;
        j = number[z - 1];
    }
    return 0;
}
