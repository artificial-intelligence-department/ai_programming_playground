#include <iostream>
using namespace std;

// Вивести масив
void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Створити однокільцевий ряд
void createRing(int arr[], int size) 
{
    int last = arr[size - 1]; 

   // Зсунути елементи вправо
    for (int i = size - 1; i > 0; i--) 
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = last; 
}

// Видалити непарні елементи
void deleteOddElements(int arr[], int size) 
{
    for (int i = 1; i < size; i += 2) 
    {
        arr[i] = 0;
    }
}

int main() 
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
  
    int k;
    cout << "Enter the value of K: ";
    cin >> k;

    // Виділення пам'яті для масиву
    int* arr = new int[size];
  
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) 
    {
        cin >> arr[i];
    }
  
    cout << "Original Array: ";
    printArray(arr, size);
    // Створення однокільцевого ряду
    createRing(arr, size);
  
    cout << "Array after creating the unidirectional ring: ";
    printArray(arr, size);

    // Додавання першого елемента в кінець масиву
    arr[size] = arr[0];
  
    cout << "Array after adding the first and last elements to the ring: ";
    printArray(arr, size + 1);
    
    // Видалення непарних елементів
    deleteOddElements(arr, size + 1);
  
    cout << "Array after deleting odd elements: ";
    printArray(arr, size + 1);
  
    cout << "Final result of array from K to K+1: ";
    for (int i = k; i <= k + 1; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
  
    delete[] arr;
    return 0;
}


