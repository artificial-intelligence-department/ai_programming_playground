#include<iostream>
using namespace std;

int user_size;

void fill_array(int* array)
{
    do
    {
        cout << "Enter size of array: ";
        cin >> user_size;
    } while (user_size > 100 || user_size < 0);
    for(int i = 0; i < user_size; i++)
    {
        int array_element;
        cout << ": ";
        cin >> array_element;
        array[i] = array_element;
    }
    cout << endl;
}

void print_array(int* array)
{
    cout << "Array[" << user_size << "] = {";
    for(int i = 0; i < user_size; i++)
    {
        cout << array[i];
        if(i != user_size - 1)
        {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

int get_k()
{
    int k;
    int size = user_size - 1;
    do
    {
        cout << "Enter k(0 - " << size << "): ";
        cin >> k;
    } while (k < 0 || k > size);
    return k;
}

void print_array_at_range(int* array, int start)
{
    int end = start - 1;
    bool end_null = false;
    if(end == -1)
    {
        end = user_size - 1;
        end_null = true;
    }
    int i;
    cout << "Array[" << user_size << "] at range (" << start << ", " << end<< ")" << " = {";
    for(i = start; i < user_size; i++)
    {
        cout << array[i];
        if(i != end)
        {
            cout << ", ";
        }
    }
    if(!end_null)
    {
        for(i = 0; i <= end; i++)
        {
            cout << array[i];
            if(i != end)
            {
                cout << ", ";
            }
        }
    }
    
    cout << "}" << endl;
}

void sort_array_by_desc(int* array)
{
    cout << "-------Sorted array by descending-------" << endl;
    for (int i = 0; i < user_size - 1; i++)
    {
        for (int y = 0; y < user_size - i - 1; y++)
        {
            if (array[y] < array[y + 1])
            {
                int temp = array[y];
                array[y] = array[y + 1];
                array[y + 1] = temp;
            }
        }
    }
}

void delete_pair_numbers(int* array)
{
    cout << "-------Deleted pair elements from array-------" << endl;
    for(int i = 0; i < user_size; i++)
    {
        if(array[i] % 2 == 0)
        {
            for(int y = i; y < user_size - 1; y++)
            {
                array[y] = array[y + 1];
            }
        }
        user_size--;
    }
}

int main()
{
    int default_size = 100;
    int array[default_size];
    fill_array(array);
    print_array(array);
    print_array_at_range(array, get_k());
    sort_array_by_desc(array);
    print_array(array);
    delete_pair_numbers(array);
    print_array(array);
    print_array_at_range(array, get_k());
}