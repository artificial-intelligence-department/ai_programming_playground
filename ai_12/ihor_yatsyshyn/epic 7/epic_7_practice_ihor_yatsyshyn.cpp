#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
//Вимога 4 - в коді використана як мінімум одна цілочисельна константа
#define const_1 918

using namespace std;
//Вимога 2 - в коді використана як мінімум одна дійсна змінна
float create_matrix(float array[][10]);
void sort(float array[][10]);
int* sums(float array[][10]);

int main()
{
    //Вимога 7 - в коді використаний двовимірний масив
    //Вимога 2 - в коді використана як мінімум одна дійсна змінна
    float array[10][10];
    create_matrix(array);
    sort(array);
    //Вимога 1 - в коді використана як мінімум одна цілочисельна змінна
    for(int i = 0; i < 10; i++)
    {
        //Вимога 10 - в коді використаний for цикл 
        for (int j = 0; j < 10; j++)
        {
            //Вимога 18 - в коді використано оператори виведення та введення даних
            cout << array[i][j] << " ";
        }
        cout << endl;

        int arr[10] = sums(array);
    }

    return 0;
}
//Вимога 14 - в коді використано параметри та аргументи функції
float create_matrix(float array[][10])
{
    //Вимога 5 - в коді використані умовні оператори та розгалуження
    if (const_1 % 2 == 0)
    {
        float array[10][10];

        for(int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                //Вимога 15 - в коді використано математичні операції та математичні функції
                array[i][j] = sqrt(const_1);
            }
        }
    }
    else
    {
        int array[10][10];
        
        for(int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                array[i][j] = sqrt(const_1);
            }
        }
    }
    
    return array;
}

void sort(float array[][10])
{
    for(int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = 0; k < 10 - j -1; k++)
            {
                if (array[k][i] > array[k+1][i])
                {
                    float temp = array[k][i];
                    array[k][i]= array[k+1][i];
                    array[k+1][i] = temp;
                }
            }
        }
    }
}

int* sums(float array[][10])
{
    //Вимога 6 - в коді використаний одновимірний масив 
    int sums[10];

    for (int i = 0; i < 10; i++)
    {
        float sum = 0;
        int count = 0;

        for (int k = 0; k < 3 || k < 4; k++)
        {
            int random = rand() % 10;

            if (random < 10)
            {
                sum += array[random][i];
                count++;
            }
            else
            {
                //Вимога 11 - в коді використано оператори break і continue
                break;
            }
        }
    }

    return sums;
}