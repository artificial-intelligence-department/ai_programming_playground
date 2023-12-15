#include <iostream>
#include<ctime>
using namespace std;

int* creation_of_array(int size)
{
    int* temp_arr = new int[size];
    for(int i = 0; i < size; i++)
    {
        temp_arr[i] = rand() % 100;
    }
    return temp_arr;
}

void print_array(int* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<< arr[i]<< " ";
    }
}

void deletion_element(int*& arr, int& size , int index)
{
    int* temp_arr = new int[size - 1];
    for(int i = 0; i < size; i++)
    {
        if (i != index)
        {
            temp_arr[i - 1] = arr[i];
        }

    }
    delete [] arr;
    arr = temp_arr;
    --size;

}

void cycle_rotating(int*& arr ,int& size, int parametr_of_rotating)
{
    int* temp_arr = new int[size];

    for(int i = size - parametr_of_rotating , j = 0; i < size && j < parametr_of_rotating;i++,j++)
    {
            temp_arr[j] = arr[i];
    }

    for(int k = size - parametr_of_rotating - 1, h = 0 ; k < size && h < size - parametr_of_rotating;k++, h++)
    {
        temp_arr[k] = arr[h];
    }
    delete [] arr;
    arr = temp_arr;


}

int main() {
    srand(time(0));
    cout << "Enter size of array: ";
    int size_arr;
    cin>> size_arr;
    int* array = creation_of_array(size_arr);
    cout << "Generated array: ";
    print_array(array, size_arr);
    deletion_element(array, size_arr, 0);
    cycle_rotating(array, size_arr, 3);
    cout <<"\nProcessed array: ";
    print_array(array, size_arr);
    delete []array;
    return 0;
}
