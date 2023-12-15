#include <iostream>
using namespace std;

int main()
{
    int N, del[3], new_size, left = 0;
    cin >> N;
    int array[N], indices[N];
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> del[i];
    }
    for (int i = 0; i < N; i++)
    {
        bool erase = false;
        for (int j = 0; j < 3; j++)
        {
            if (array[i] == del[j])
            {
                erase = true;
                break;
            }
        }
        if (erase == false)
        {
            indices[left] = i;
            left++;
        }
    }
    new_size = left - 1;
    if (new_size > 0)
    {
        int new_array[new_size];
        for (int i = 0, j = 1; j < left; i++, j++)
        {
            new_array[i] = array[indices[j]] + array[indices[j - 1]];
        }
        cout << new_size << endl;
        for (int i = 0; i < left - 1; i++)
        {
            cout << new_array[i] << ' ';
        }
    }
    else cout << '0';
    return 0;
}