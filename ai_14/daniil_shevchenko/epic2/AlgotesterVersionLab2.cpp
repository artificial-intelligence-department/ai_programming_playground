#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> array;
    array.resize(N);
    int extra[3];
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> extra[i];
    }

    vector<int> newarray;
    newarray.resize(N);

    int j = 0;
    for (int i = 0; i < N; i++)
    {
        if (array[i] != extra[0] && array[i] != extra[1] && array[i] != extra[2])
        {
            newarray[j] = array[i];
            j++;
        }
    }
    newarray.resize(j);

    vector<int> finalarray;
    if (j > 1)
    {
        finalarray.resize(j - 1);
        cout << j - 1 << endl;
        for (int i = 0; i < j - 1; i++)
        {
            finalarray[i] = newarray[i] + newarray[i + 1];
            cout << finalarray[i] << " ";
        }
    }
    else
    {
        cout << 0;
    }
}