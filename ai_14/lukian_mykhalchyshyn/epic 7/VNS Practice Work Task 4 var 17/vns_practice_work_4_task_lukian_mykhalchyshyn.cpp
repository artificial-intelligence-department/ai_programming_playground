#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    const int min = 1, max = 10, length = 10; //цілочисельна константа

    int range = max - min + 1; // цілочиселна змінна
    for(int i = 0; i < 3; ++i) // цикл 
    {
        cout << "Послідовність: "; //оператор виведення

        int sum = 0;

        for (int j = 0; j < length; j++)
        {
            int num = rand() % range + min; 
            cout << num << " ";
            sum += num; 
        }
    
        double M = static_cast <double> (sum) / length; // дійсна змінна з подвійною точніссю

        cout << "Середнє арифметичне: " << M << endl << endl;
    }

    return 0;
}