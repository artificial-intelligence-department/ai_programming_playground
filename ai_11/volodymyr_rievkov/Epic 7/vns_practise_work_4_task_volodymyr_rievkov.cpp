#include<iostream>
using namespace std;

void set_size(int &size)
{
    cout << "Enter size: ";
    cin >> size;
}

void fill_array(double* array, int size)
{
    cout << "----Enter numbers----" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << ": ";
        cin >> array[i];

    }
    cout << endl;
}

void print_array(double* array, int size)
{
    cout << "Array[" << size << "] = {";
    for(int i = 0; i < size; i++)
    {
        cout << array[i];
        if(i != size - 1)
        {
            cout << ", ";
        }
    }
    cout << "}" << endl;
    cout << endl;
}

void set_max(double* array, int size, double &max)
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
    }
}

void set_min(double* array, int size, double &min, double max)
{
    min = max;
    for(int i = 0; i < size; i++)
    {
        if(array[i] < min)
        {
            min = array[i];
        }
    }
}

void set_avg(double* array, int size, double &avg)
{
    for(int i = 0; i < size; i++)
    {
        avg += array[i];
    }
    avg /= size;
}

int main()
{
    int size;
    set_size(size);
    double array[size];
    fill_array(array, size);
    print_array(array, size);
    double max;
    set_max(array, size, max);
    double min;
    set_min(array, size, min, max);
    double avg;
    set_avg(array, size, avg);
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    cout << "Avg: " << avg << endl;
}