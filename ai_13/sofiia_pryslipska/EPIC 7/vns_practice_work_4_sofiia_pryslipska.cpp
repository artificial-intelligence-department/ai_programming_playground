#include <iostream>
using namespace std;
int main()
{
    double array[5];
    cout << "enter 5 fractional numbers:" << endl;
  //ввід чисел за допомогою циклу
    for (int i = 0; i < 5; i++)
    {
        cin >> array[i];
    }
    double max = array[0];
    double min = array[0];
    double sum = 0;
    double average;
//пошук максимального значення
    for (int i = 0; i < 5; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    //пошук мінімального значення
    for (int i = 0; i < 5; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    //обчислення суми чисел
    for (int i = 0; i < 5; i++)
    {


        sum += array[i];
    }
    average = sum / 5; //обчислення середнього арифметичного
    cout << "the maximum sequence number: " << max << endl;
    cout << "the minimum sequence number: " << min << endl;
    cout << "the arithmetic average number of sequences: " << average << endl;


    return 0;
}
