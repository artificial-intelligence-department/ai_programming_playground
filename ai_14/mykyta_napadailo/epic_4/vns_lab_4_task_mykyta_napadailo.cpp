#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(nullptr));
    int a[100];
    int s;
    cout << "Enter the size of your array: ";
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        a[i] = rand() % 10;
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < s; i++)
    {
        if (a[i] == 0)
        {
            for (int j = i; j < s - 1; j++)
            {
                a[j] = a[j + 1];
            }
            s--;
            break;
        }
    }
    for (int i = 0; i < s; i++)
    {
        if (a[i] % 2 == 0)
        {
            s++;
            for (int j = s - 1; j > i; j--)
            {
                a[j] = a[j - 1];
            }
            i++;
            a[i] = a[i - 1] + 2;
        }
    }
    for (int i = 0; i < s; i++) cout << a[i] << " ";
}