
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
void downgradesort(int array[], int length)
{

    for (int startindex = 0; startindex < length; startindex++)
    {
        int maxindex = startindex;
        for (int currentindex = startindex; currentindex < length; currentindex++)
        {
            if (array[currentindex] > array[maxindex])
            {
                maxindex = currentindex;
            }
        }
        swap(array[startindex], array[maxindex]);
    }
}


int main()
{
    int N;
    cin >> N;
    int* array = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }
    int* array0 = new int[N];
    int* array1 = new int[N];
    int* array2 = new int[N];
    int l0, l1, l2;
    l0 = 0;
    l1 = 0;
    l2 = 0;
    for (int i = 0; i < N; i++)
    {
        if (array[i] % 3 == 0)
        {
            array0[l0] = array[i];
            l0++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (array[i] % 3 == 1)
        {
            array1[l1] = array[i];
            l1++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (array[i] % 3 == 2)
        {
            array2[l2] = array[i];
            l2++;
        }
    }
    upgradesort(array0, l0);
    upgradesort(array2, l2);
    downgradesort(array1, l1);
    int* newarray = new int[N];
    for (int i = 0, k = 0; k < l0; i++, k++)
    {
        newarray[i] = array0[k];
    }
    for (int i = l0, k = 0; k < l1; i++, k++)
    {
        newarray[i] = array1[k];
    }
    for (int i = l0+l1, k = 0; k < l2; i++, k++)
    {
        newarray[i] = array2[k];
    }
    
    int* finalarray = new int[N];
    int newsize = 0;
    for (int i = 0; i < N; i++)
    {
        bool presence = false;
        for (int j = 0; j < newsize; j++)
        {
            if (finalarray[j] == newarray[i])
            {
                presence = true;

            }

        }
        if (!presence)
        {
            finalarray[newsize] = newarray[i];
            newsize++;
        }
    }
    cout << newsize << endl;
    for (int i = 0; i < newsize; i++)
    {
        cout << finalarray[i] << " ";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
