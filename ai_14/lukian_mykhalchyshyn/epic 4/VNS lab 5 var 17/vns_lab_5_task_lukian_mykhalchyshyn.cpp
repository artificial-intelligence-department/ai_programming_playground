#include <iostream>

using namespace std;

int main()
{
    int N, M, Max_Sum = 0, sum, Max_row = 0, Max_col = 0;

    cout << "Введіть кількість рядків: ";
    cin >> N;

    cout << "Введіть кількість стовпців: ";
    cin >> M;
    cout << endl;

    while (N < 3 || N > 100 || M < 3 || M > 100)
    {
        cout << "Розмір масивів має бути від 3 до 100\n";
        cout << "Введіть кількість рядків: ";
        cin >> N;
        
        cout << "Введіть кількість стовпців: ";
        cin >> M;
    }

    int arr[100][100];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cout << "Введіть елементи масиву [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> arr[i][j];
        }
    }

    Max_Sum = arr[0][0] + arr[0][1] + arr[0][2] + arr[1][0] + arr[1][1] + arr[1][2] + arr[2][0] + arr[2][1] + arr[2][2]; // встановлення початкового значення для Max_Sum

    for (int i = 0; i < N - 3; ++i)
    {
        for (int j = 0; j < M - 3; ++j)
        {
            sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]; // сума елементів підмасиву

            if (sum > Max_Sum) // поточна сума і максимальна
            {
                Max_Sum = sum;
                Max_row = i;
                Max_col = j;
            }        
        }
    }

    
    cout << "Максимальна сума елементів в підмасиві 3 на 3: " << Max_Sum << endl;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << arr[Max_row + i][Max_col + j] << " ";
        }
        cout << endl;
    }

    return 0;
}