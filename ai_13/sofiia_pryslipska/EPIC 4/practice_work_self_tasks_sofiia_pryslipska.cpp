#include <iostream>
using namespace std;

int main()
{

    const int SIZE = 8;
    int numbers[SIZE] = {560, 456, 124, 912, 12, 365, 612, 111};

    cout << "the elements of array:" << endl;
    for (int i = 0; i < SIZE; ++i)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    double sum = 0;
    for (int i = 0; i < SIZE; ++i)
    {
        sum += numbers[i];
    }
    double average = sum / SIZE;

    cout << "The average value of the array elements: " << average << endl;

    return 0;
}