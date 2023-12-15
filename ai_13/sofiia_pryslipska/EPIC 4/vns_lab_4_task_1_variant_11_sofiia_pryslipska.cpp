#include <iostream>
#include <vector>
// для використання функцій rand() і srand() для генерації випадкових чисел.
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    vector<int> arr(15);

    srand(time(NULL));

    for (int i = 0; i < arr.size(); ++i)
    {
        arr[i] = rand() % 100;
    }

    cout << "Initial array:" << endl;
    for (int elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Знищення 5 останніх елементів масиву
    arr.resize(arr.size() - 5);

    // Додавання 3 елементів в початок масиву зі значенням M[I+1]+2
    for (int i = 0; i < 3; ++i)
    {

        arr.insert(arr.begin(), arr[i + 1] + 2);
    }

    cout << "Array after operations:" << endl;
    for (int elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
