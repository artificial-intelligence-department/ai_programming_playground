#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cout << "N: ";
    cin >> N;
    vector<int> array;
    array.resize(N);
    int extra[3];
    cout << "Enter " << N << " array elements: " << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }
    cout << "Enter 3 extra numbers: " << endl;
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
    cout << "The new array is: " << endl;

    for (int i = 0; i < j; i++)
    {
        cout << newarray[i] << " ";
    }
    cout << endl;

    vector<int> finalarray;
    if (j > 1)
    {
        finalarray.resize(j - 1);
        cout << "The amount of elements in the final array is: " << j - 1 << endl;
        cout << "The final array is: " << endl;
        for (int i = 0; i < j - 1; i++)
        {
            finalarray[i] = newarray[i] + newarray[i + 1];
            cout << finalarray[i] << " ";
        }
    }
    else
    {
        cout << "Final result: 0";
    }
}