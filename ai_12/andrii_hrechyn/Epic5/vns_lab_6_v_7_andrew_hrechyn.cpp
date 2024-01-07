#include <iostream>
#include <string>
using namespace std;

void bubbleSort(int zrozumiv[], int size);

int main()
{
    string text;
    getline(cin, text);
    int size = text.length();
    int zrozumiv[size];

    for(int i = 0; i < size; i++)
    {
        int number = text[i] - '0';
        zrozumiv[i] = number;
    }

    bubbleSort(zrozumiv, size);

    for(int i = 0; i < size; i++)
    {
        cout << zrozumiv[i] << " ";
    }
    return 0;
}

void bubbleSort(int zrozumiv[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            
            if (zrozumiv[j] < zrozumiv[j + 1])
            {
                int temp = zrozumiv[j];
                zrozumiv[j] = zrozumiv[j + 1];
                zrozumiv[j + 1] = temp;
            }
        }
    }
}
