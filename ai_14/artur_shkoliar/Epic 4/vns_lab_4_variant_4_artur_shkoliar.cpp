#include <iostream>
#include <cstdlib>

using namespace std;

void arrays(int arr[], int size) {
    for (int i = 0; i < size; ++i) 
    {
        cout << arr[i] << " " << endl;
    }

}

int randnumb(int max) 
{
    return rand() % (max + 1);
}

int main() 
{
    
    const int arraysize = 10; 
    int* array = new int[arraysize];

    for (int i = 0; i < arraysize; ++i) 
    {
        array[i] = randnumb(40); 
    }

    cout << "Початковий масив: ";
    arrays(array, arraysize);

   
    int newone = 0;
    for (int i = 0; i < arraysize; ++i) 
    {
        if (i % 3 != 0) 
        {
            array[newone++] = array[i];
        }
    }

    
    for (int i = newone - 1; i >= 0; --i) 
    {
        if (array[i] < 0) 
        {
            int newcount = abs(array[i - 1] + 1);
            newone++;
            for (int j = newone - 1; j > i; --j) 
            {
                array[j] = array[j - 1];
            }
            array[i + 1] = newcount;
        }
    }

    cout << "Отриманий масив: ";
    arrays(array, newone);

    return 0;
}
