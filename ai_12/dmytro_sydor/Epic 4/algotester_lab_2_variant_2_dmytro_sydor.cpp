#include <iostream>
using namespace std;

int main()
{

    int size;

    cin >> size;

    int arr[size];
    size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int elementToDelete1, elementToDelete2, elementToDelete3;

    cin >> elementToDelete1 >> elementToDelete2 >> elementToDelete3; // The element you want to delete

    // Знаходимо індекс елемента котрий потрібно видалити
    int indexToDelete = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == elementToDelete1)
        {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete != -1)
    {
        // Створюємо новий масив без елемента котрий ми видалили
        int newArray[size - 1];
        for (int i = 0, j = 0; i < size; i++)
        {
            if (i != indexToDelete)
            {
                newArray[j] = arr[i];
                j++;
            }
        }

        // Копіюємо новий масив в старий
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = newArray[i];
        }

        size--;
    }

    // Другий елемент , котрий потрібно видалити;

    indexToDelete = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == elementToDelete2)
        {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete != -1)
    {
        // Створюємо новий масив без елемента котрий ми хочемо видалити
        int newArray[size - 1];
        for (int i = 0, j = 0; i < size; i++)
        {
            if (i != indexToDelete)
            {
                newArray[j] = arr[i];
                j++;
            }
        }

        // Копіюємо новий масив в старий
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = newArray[i];
        }

        size--;
    }

    // Третій елемент

    indexToDelete = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == elementToDelete3)
        {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete != -1)
    {
        // Створюємо новий масив без елемента котрий ми хочемо видалити
        int newArray[size - 1];
        for (int i = 0, j = 0; i < size; i++)
        {
            if (i != indexToDelete)
            {
                newArray[j] = arr[i];
                j++;
            }
        }

        // Копіюємо ноаий масив в старий
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = newArray[i];
        }

        size--;
    }

    if (size <= 1)
    {
        if (size == 1)
        {
            size -= 1;
            cout << size << endl;
        }
        else
        {
            cout << size << endl;
        }
        return 0;
    }

    int result[size]; // Масив для зберігання сум

    for (int i = 0; i < size; i++)
    {
        int rightElementIndex = i + 1;
        if (rightElementIndex < size)
        {
            result[i] = arr[i] + arr[rightElementIndex];
        }
        else
        {
            result[i] = 0; // Якщо немає елемента справа, то сума дорівнює 0
        }
    }

    int finalArr[size - 1];
    for (int i = 0, j = 0; i < size; i++)
    {
        if (result[i] != 0)
        {
            finalArr[j] = result[i];
            j++;
        }
    }

    int res = sizeof(finalArr) / sizeof(int);
    cout << res << endl;

    for (int i = 0; i < size; i++)
    {
        if (result[i] != 0)
        {
            cout << result[i] << " ";
        }
    }

    return 0;
}