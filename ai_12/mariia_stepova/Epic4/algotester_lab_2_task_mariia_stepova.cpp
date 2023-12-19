#include <iostream>
#include <ctime>

using namespace std;

void init(int* arr, int size);//ініціалізація матриці(заповнюємо з клавіатури значеннями)
void print(int* arr, int size);//вивід матриці на консоль
void erace(int* &arr, int &size, int index);
void erace_all_num(int* &arr, int &size, int num);
void sum(int* &arr, int &size);

int main()
{
    srand(time(0));
    int size = 0;
    
    cin >> size;
    int *arr = new int[size];
    
    init(arr, size);
    int a, b, c;
    cin >> a >> b >> c;
    
    erace_all_num(arr, size, a);
    erace_all_num(arr, size, b);
    erace_all_num(arr, size, c);
    
    if(size != 0)
    {
        sum(arr, size);
        cout << size << endl;
        print(arr, size);
    }
    else
        cout << 0 << endl;
    delete[]arr;
    return 0;
}

void init(int* arr, int size)//ініціалізація матриці(заповнюємо з клавіатури значеннями)
{
    for(int i = 0; i < size; i++)
     cin >> arr[i];
}
void print(int* arr, int size)//вивід матриці на консоль
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
void erace(int* &arr, int &size, int index)
{
    int *arr_new = new int[--size];
    
    for(int i = 0, j = 0; i < size + 1; i++)
        if(i != index)
            arr_new[j++] = arr[i];
    delete[]arr;
    arr = arr_new;
}
void erace_all_num(int* &arr, int &size, int num)
{
    for(int i = 0; i < size; i++)
        if(arr[i] == num)
        { 
            erace(arr, size, i);
            i--;
        }
}
void sum(int* &arr, int &size)
{
    int *arr_new = new int[--size];
    
    for(int i = 0; i < size; i++)
        arr_new[i] = arr[i] + arr[i + 1];
    
    delete[]arr;
    arr = arr_new;
}

