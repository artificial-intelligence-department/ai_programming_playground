#include <iostream>
#include <vector>
using namespace std;
void upgradesort(vector<int>& array, int length)
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
int presentcounter(int element, vector<int> array, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            count++;
        }
    }
    return count;
}
int max(int x, int y)
{
    if (x >= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int min(int x, int y)
{
    if (x <= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int main()
{
    int N;
    cin >> N;
    vector<int> array1;
    array1.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> array1[i];
    }
    int M;
    cin >> M;
    vector<int> array2;
    array2.resize(M);
    for (int i = 0; i < M; i++)
    {
        cin >> array2[i];
    }
    // difference N-M
    vector<int> difference12;
    difference12.resize(N);
    int indexdif12 = 0;
    for (int i = 0; i < N; i++)
    {
        if (presentcounter(array1[i], difference12, indexdif12) == 0)
        {
            int x = presentcounter(array1[i], array1, N);
            int y = presentcounter(array1[i], array2, M);
            int k = x - y;
            if (x > y)
            {
                for (int j = 0; j < k; j++)
                {
                    difference12[indexdif12] = array1[i];
                    indexdif12++;
                }
            }
        }
    }
    cout << indexdif12 << endl;
    upgradesort(difference12, indexdif12);
    for (int i = 0; i < indexdif12; i++)
    {
        cout << difference12[i] << " ";
    }
    cout << endl;
    // difference M-N
    vector<int> difference21;
    difference21.resize(M);
    int indexdif21 = 0;
    for (int i = 0; i < M; i++)
    {
        if (presentcounter(array2[i], difference21, indexdif21) == 0)
        {
            int x = presentcounter(array2[i], array2, M);
            int y = presentcounter(array2[i], array1, N);
            int k = x - y;
            if (x > y)
            {
                for (int j = 0; j < k; j++)
                {
                    difference21[indexdif21] = array2[i];
                    indexdif21++;
                }
            }
        }
    }
    cout << indexdif21 << endl;
    upgradesort(difference21, indexdif21);
    for (int i = 0; i < indexdif21; i++)
    {
        cout << difference21[i] << " ";
    }
    cout << endl;
    // intersection
    vector<int> intersection;
    intersection.resize(N);
    int indexinter = 0;
    for (int i = 0; i < N; i++)
    {
        if (presentcounter(array1[i], intersection, indexinter) == 0)
        {
            int x = presentcounter(array1[i], array1, N);
            int y = presentcounter(array1[i], array2, M);
            int k = min(x, y);
            if (k > 0)
            {
                for (int j = 0; j < k; j++)
                {
                    intersection[indexinter] = array1[i];
                    indexinter++;
                }
            }
        }
    }
    cout << indexinter << endl;
    upgradesort(intersection, indexinter);
    for (int i = 0; i < indexinter; i++)
    {
        cout << intersection[i] << " ";
    }
    cout << endl;
    // addition
    vector<int> consolidation;
    consolidation.resize(N+M);
    int indexcon = 0;
    for (int i = 0; i < N; i++)
    {
        if (presentcounter(array1[i], consolidation, indexcon) == 0)
        {
            int x = presentcounter(array1[i], array1, N);
            int y = presentcounter(array1[i], array2, M);
            int k = max(x, y);
            if (k > 0)
            {
                for (int j = 0; j < k; j++)
                {
                    consolidation[indexcon] = array1[i];
                    indexcon++;
                }
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        if (presentcounter(array2[i], consolidation, indexcon) == 0)
        {
            int x = presentcounter(array2[i], array2, M);
            int y = presentcounter(array2[i], array1, N);
            int k = max(x, y);
            if (k > 0)
            {
                for (int j = 0; j < k; j++)
                {
                    consolidation[indexcon] = array2[i];
                    indexcon++;
                }
            }
        }
    }
    cout << indexcon << endl;
    upgradesort(consolidation, indexcon);
    for (int i = 0; i < indexcon; i++)
    {
        cout << consolidation[i] << " ";
    }
    cout << endl;
    //symmetric difference
    vector<int> symdif;
    symdif.resize(N+M);
    int indexsym = 0;
    for (int i = 0; i < indexdif12; i++)
    {
        symdif[i] = difference12[i];
    }
    for (int i = 0; i < indexdif21; i++)
    {
        symdif[indexdif12 + i] = difference21[i];
    }
    upgradesort(symdif, indexdif12 + indexdif21);
    cout << indexdif12 + indexdif21 << endl;
    for (int i = 0; i < indexdif12 + indexdif21; i++)
    {
        cout << symdif[i] << " ";
    }


}

