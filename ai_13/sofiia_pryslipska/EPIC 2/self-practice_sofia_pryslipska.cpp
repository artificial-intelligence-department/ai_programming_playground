
//виводить мін і макс значення і середнє арифметичне

#include <iostream>
using namespace std;
int main()
{
    int amount = 5;
    int number[5];
   
    cout << "enter 5 numbers:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> number[i];
    }

    int max = number[0];
    for (int i = 0; i < 5; i++)
    {
        if (max < number[i])
        {
            max = number[i];
        }
    }
    cout << "the maximal number is:" << max << endl;

    int min = number[0];
    for (int i = 0; i < 5; i++)
    {
        if (min > number[i])
        {
            min = number[i];
        }
    }
    cout << "the minimal number is:" << min << endl;

   
    double sum=0;
    for (int i = 0; i <5; i++)
    {
     sum=sum+number[i];
    }
    cout<<sum;
    cout<<"the arithmetic mean of your numbers:"<<sum/5;
    return 0;
}