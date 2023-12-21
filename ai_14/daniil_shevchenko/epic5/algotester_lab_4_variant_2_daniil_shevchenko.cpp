#include <iostream>
using namespace std;
void swap(int& a, int& b)
{

    int x = a;
    a = b;
    b = x;
}
void upgradesort(int array[], int length)
{

    for (int startindex = 0; startindex < length; startindex++)
    {
        int minindex = startindex;
        for (int currentindex = startindex; currentindex < length; currentindex++)
        {
            if (array[currentindex] < array[minindex])
            {
                minindex = currentindex;
            }
        }
        swap(array[startindex], array[minindex]);
    }
}

int main()
{
    int N, K;
    cin >> N >> K;
    int* array1 = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> array1[i];
    }
    int* array2 = new int[N];
    int newsize = 0;
    for (int i = 0; i < N; i++)
    {
        bool presence = false;
        for (int j = 0; j < newsize; j++)
        {
            if (array2[j] == array1[i])
            {
                presence = true;

            }

        }
        if (!presence)
        {
            array2[newsize] = array1[i];
            newsize++;
        }
    }

    upgradesort(array2, newsize);

    int m = K % newsize;
    int* array3 = new int[newsize];
    for (int t = m; t < newsize; t++)
    {
        array3[t - m] = array2[t];
    }
    for (int i = newsize - m, f = 0; f < m; i++, f++)
    {
        array3[i] = array2[f];
    }
    cout << newsize << endl;
    for (int i = 0; i < newsize; i++)
    {
        cout << array3[i] << " ";
    }



}
