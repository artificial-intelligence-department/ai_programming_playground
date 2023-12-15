#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int N = 100;
    int a[N];
    int length;

    cout << "Enter the length of the array: ";
    cin >> length;

    for(int i = 0; i < length; i++)
    {
        a[i] = rand()%10;
    }
    
    cout << "Received array: ";

    for(int i = 0; i < length; i++)
    {
        cout << a[i] << " ";
    }
    
    cout << endl;

    int delete_number;

    cout << "Which elements do you want to delete? (Enter one number)" << endl;
    cin >> delete_number;

    int index_delete_number = -1;

    for(int i = 0; i < length; i++)
    {
        if(a[i] == delete_number)
        {
            --N;
            --length;
            index_delete_number = i;

            for(int j = i; j < length; j++)
            {
                a[j] = a[j + 1];
            }
        }
    }

    if(index_delete_number == -1)
    {
        cout << "There wasnn't such an element in this array" << endl;
    }

    for(int i = 0; i < length; i++)
    {
        if(a[i] % 2 == 0)
        {
            ++N;
            ++length;

            for(int j = length - 1; j > i; j--)
            {
                a[j] = a[j - 1];
            }
            
            a[i] = 0;
            ++i;
        }
    }

    cout << "New array is: " << endl;

    for (int i = 0; i < length; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}
