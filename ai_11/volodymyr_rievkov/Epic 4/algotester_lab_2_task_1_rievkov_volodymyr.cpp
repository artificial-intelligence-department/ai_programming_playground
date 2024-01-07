#include<iostream>
using namespace std;

const int border = 100000;
const int flag = -1;

int get_size()
{
    int size;
    cin >> size;
    return size;
}

void fill_array(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
}

bool is_array_right(int* array, int size)
{
    int count;
    for(int i = 0 ; i < size; i++)
    {
        if(array[i] < 0 || array[i] > border)
        {
            return false;
        }
    }
    return true;
}

int get_max_array_number(int* array, int size)
{
    int max = 0;
    for(int i = 0; i < size; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

int get_min_array_number(int* array, int size, int max)
{
    int min = max;
    for(int i = 0; i < size; i++)
    {
        if(array[i] < min && array[i] != flag)
        {
            min = array[i];
        }
    }
    return min;
}

int get_count_of_array_number(int* array, int size, int number)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(number == array[i])
        {
            count++;
        }
    }
    return count;
}

void delete_array_number(int* array, int size, int number)
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] == number)
        {
            array[i] = flag;
            break;
        }
    }
}

void restore_array_number(int* array, int size, int number)
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] == flag)
        {
            array[i] = number;
            break;
        }
    }
}

int get_result(int* array, int size)
{
    int tempMax;
    int tempMin;
    int result1, result2;
    int max = get_max_array_number(array, size);
    int min = get_min_array_number(array, size, max);
    int max_count = get_count_of_array_number(array, size, max);
    int min_count = get_count_of_array_number(array, size, min);
    if(max_count == min_count)
    {
        delete_array_number(array, size, max);
        tempMax = max;
        max = get_max_array_number(array, size);
        result1 = max - min;
        delete_array_number(array, size, min);
        tempMin = min;
        min = get_min_array_number(array, size, tempMax);
        result2 = tempMax - min;
        if(result1 > result2)
        {
            restore_array_number(array, size, tempMax);
        }
        else
        {
            restore_array_number(array, size, tempMin);
        }
    }
    if(max_count > min_count)
    {
        delete_array_number(array, size, min);
    }
    if(max_count < min_count)
    {
        delete_array_number(array, size, max);
    }
    max = get_max_array_number(array, size);
    min = get_min_array_number(array, size, max);
    return max - min;
}

int main()
{
    int size = get_size();
    if(size < 1 || size > border)
    {
        return 0;
    }
    int a_road[size];
    fill_array(a_road, size);
    if(!is_array_right(a_road, size))
    {
        return 0;
    }
    cout << get_result(a_road, size);
}