#include <iostream>

using namespace std;

void genAr(int arr[], int length);
void delFirst(int ar[], int length, int b);
void printAr(int ar[], int length);

int main()
{
    int N = 100, length, buffer, temp;
    int a[N];
    srand (time(NULL));

    cout << "Input length (<= 50): ";
    if(!(cin >> length) && length <= 50 && length > 0)
    {
        cout << "Wrong input!\n";
        return 0;
    }

    genAr(a, length);

    
    // Deleting first a[i] == 0.
    delFirst(a, length, 0);

    // After each even element of the array, add an element with the value M[i-1]+2.
    for(int i  = 0; i < length; i++)
    {
        if(a[i] % 2 == 0)
        {   
            i++;
            buffer  = a[i];
            a[i] = a[i-1] + 2;
            length++;

            int j = i + 1;

            while(j < length)
            {
                temp = a[j];
                a[j] = buffer;
                buffer = temp;
                j++;
            }
        }
    }

    printAr(a, length);

    return 0;
}
void genAr(int ar[], int length)
{
    // Generating and printing an array.
    for(int i = 0; i < length; i++)
    {
        ar[i] = rand();
        cout << ar[i] << " ";
    }
    cout << endl;
    return;
}
void delFirst(int ar[], int length, int b)
{
    // Deleting first a[i] == b.
    for(int i = 0; i < length; i++)
    {
        if(ar[i] == b)
        {
            while(i + 1 < length)
            {
                ar[i] = ar[i + 1];
                i++;
            }
            length--;
            break;
        }
    }
    return;
}
void printAr(int ar[], int length)
{
    // Print an array.
    for(int i = 0; i < length; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
    return;
}
