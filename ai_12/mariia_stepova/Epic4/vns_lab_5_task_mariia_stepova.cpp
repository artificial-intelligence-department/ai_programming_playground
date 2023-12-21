#include <iostream>
#include <ctime>
#define row 5
#define col 5
using namespace std;

void init(int arr[row][col]);//ініціалізація матриці(заповнюємо випадковими значеннями)
void print(int arr[row][col]);//вивід матриці на консоль
void func(int arr[row][col]);//функція з умови завдання


int main()
{
    srand(time(0));
    int arr[row][col];
    
    init(arr);
    print(arr);
    func(arr);
    cout << endl;
    print(arr);
    cout << endl;
    return 0;
}

void init(int arr[row][col])//ініціалізація матриці(заповнюємо випадковими значеннями)
{
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            arr[i][j] = rand() % 10;
}
void print(int arr[row][col])//вивід матриці на консоль
{
    for(int i = 0; i < row; i++)
    { 
        for(int j = 0; j < col; j++)
           cout << arr[i][j] << " ";
        cout << endl;
    }
}
void func(int arr[row][col])//функція з умови завдання
{
    bool growth, decrease;
    
    for(int i = 0; i < row; i++)
    {
        growth = 1, decrease = 1;
        for(int j = 0; j < col - 1; j++)
        {
            if(arr[i][j] > arr[i][j + 1])
                growth = 0;
            if(arr[i][j] < arr[i][j + 1])
                decrease = 0;
        }
        cout << "String number - " << i << ": ";
        if(growth)
            cout << "growth\n";
        else if(decrease)
            cout << "decrease\n";
        else 
            cout << "disordered\n";
        if(decrease == 0)
        {
            for(int q = 0; q < col; q++)
                for(int j = col - 1; j > q; j--)
                    if(arr[i][j] < arr[i][j - 1])
                        swap(arr[i][j], arr[i][j - 1]);
        }
    }
    
}