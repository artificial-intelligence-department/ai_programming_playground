#include <iostream>
#include <cmath>
using namespace std;

// Функція для сортування масиву відстаней методом швидкого сортування
void quickSort(double distance[], int left, int right)     //Метод швидкого сортування (QuickSort) - це швидкий та ефективний алгоритм сортування, який використовує стратегію "розділяй і володарюй". Він базується на принципі 
                                                           // розбиття масиву на менші частини за допомогою опорного елемента (pivot), після чого елементи розташовуються навколо цього опорного елемента. Алгоритм виконується 
                                                           //рекурсивно для кожної з частин, поки масив не буде відсортований.
{

    int i = left, j = right;
    double temp;
    double pivot = distance[(left + right) / 2]; // Вибір опорного елемента (pivot)
 
    //алгоритм швидкого сортування
    while (i <= j) 
    {
        while (distance[i] < pivot)
            i++;
        while (distance[j] > pivot)
            j--;
        if (i <= j) 
        {
            // Обмін елементів
            temp = distance[i];
            distance[i] = distance[j];
            distance[j] = temp;
            i++;
            j--;
        }
    }
 
    // Рекурсивні виклики для сортування підмасивів
    if (left < j)
    {
        quickSort(distance, left, j);
    }
    if (i < right)
    {
        quickSort(distance, i, right);
    }
}

int main()
{
    //координати дому
    long X;
    long Y;
    cin >> X >> Y;

    //кількість точок і кількість разів
    int n;
    int k;
    cin >> n >> k;

    long x[n];
    long y[n];
    double distance[n];    //масив для зберігання відстаней від дому до точок

    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        distance[i] = sqrt(pow(X - x[i], 2) + pow(Y - y[i], 2)); // Визначення відстані за формулою відстані між точками у просторі
    }

    // Сортування масиву відстаней методом швидкого сортування
    quickSort(distance, 0, n - 1);

    //вивід найменшої відстані на яку було видно дим
    cout << distance[k - 1];
    return 0;
}