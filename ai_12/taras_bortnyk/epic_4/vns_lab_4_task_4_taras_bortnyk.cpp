#include <iostream>
#include <ctime>

using namespace std;

void add(int* &arr, int &size, int index, int num);
void del_el(int* &arr, int &size, int index);

int main()
{
   srand(time(0));
   int size;
   cout << "Enter size: ";
   cin >> size; 
   int* arr = new int[size];
   
   for(int i = 0; i < size; i++)
   {
       arr[i] = rand() % 19 - 9;
       cout << arr[i] << " ";
   }
   cout << endl;
    for(int i = 3; i < size; i += 3)
        del_el(arr, size, i--);
    
    for(int i = 0; i < size; i++)
        if(arr[i] < 0)
            add(arr, size, ++i, arr[i] + 1);
               
    for(int i = 0; i < size; i++)
         cout << arr[i] << " ";
         
   //??? % 3 == 0
   //0 % 3 == 0
   //1 % 3 == 1
   //3 % 3 == 0
    return 0;
}

void add(int* &arr, int &size, int index, int num)
{
    int* new_arr = new int[++size];
    
    for(int i = 0; i < size; i++)
    {
        if(i < index)
            new_arr[i] = arr[i];
        else if(i == index)
            new_arr[i] = num;
        else
            new_arr[i] = arr[i - 1];
    }
    delete[]arr;
    arr = new_arr; 
}

void del_el(int* &arr, int &size, int index)
{
    int* new_arr = new int[--size];
    
    for(int i = 0, j = 0; i < size + 1; i++)
        if(i != index)
        new_arr[j++] = arr[i];
    delete[]arr;
    arr = new_arr;
}

/*

1) Сформувати одновимірний масив цілих чисел, використовуючи генератор
випадкових чисел.
2) Роздрукувати отриманий масив.
3) Знищити елементи, індекси яких кратні 3.
4) Додати після кожного від’ємного елемента масиву елемент зі значенням | M[I-1 ]+1 |.

*/