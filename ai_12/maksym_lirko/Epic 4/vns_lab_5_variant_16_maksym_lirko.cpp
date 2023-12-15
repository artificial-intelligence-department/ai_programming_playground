#include<iostream>
#include<ctime>
using namespace std;

int main()
{
    int N; 
    cin >> N;

    int array[N][N];

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            array[i][j] = rand() % 20;
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << endl << endl;
    
    for (int j = 0; j < N; j++) 
    {    
        for (int i = 0; i < N - 1; i++) 
        {   
            if (array[i][j] < array[i + 1][j]) 
            {
                swap(array[i][j], array[i + 1][j]);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}
