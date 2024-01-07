#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int length;
    int K;
    cout << "Введіть кількість елементів для масиву: ";
    cin >> length;
    vector<int> array;
    cout << "Введіть значення для K: ";
    cin >> K;

    for (int i = 0; i < length; i++)
    {
        array.push_back(i + 1);
    }

    for (int i = K - 1; i < length; i++)
    {
        cout << array[i] << " ";
    }
    for (int i = 0; i < K - 1; i++)
    {
        cout << array[i] << " ";
    }

    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] % 5 == 0)
        {
            array.insert(array.begin() + i + 1, 0);
            i++;
        }
    }

    cout << endl;

    for (int i = K - 1; i >= 0; i--)
    {
        cout << array[i] << " ";
    }
    for (int i = array.size() - 1; i > K - 1; i--)
    {
        cout << array[i] << " ";
    }

    return 0;
}
