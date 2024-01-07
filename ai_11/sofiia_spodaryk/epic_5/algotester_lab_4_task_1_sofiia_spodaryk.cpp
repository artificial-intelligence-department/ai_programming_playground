#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int N;
    cout << "Введіть розмір першого масиву (N): ";
    cin >> N;

    vector<int> array1(N);
    cout << "Введіть елементи першого масиву: ";
    for (int i = 0; i < N; ++i)
    {
        cin >> array1[i];
    }

    int M;
    cout << "Введіть розмір другого масиву (M): ";
    cin >> M;

    vector<int> array2(M);
    cout << "Введіть елементи другого масиву: ";
    for (int i = 0; i < M; ++i)
    {
        cin >> array2[i];
    }

    // Різниця N-M
    vector<int> difference1;
    set_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(difference1)); 
    cout << "Різниця N-M: " << difference1.size() << endl; 
    for (const auto &element : difference1)
    {
        cout << element << " ";
    }
    cout << endl;

    // Різниця M-N
    vector<int> difference2;
    set_difference(array2.begin(), array2.end(), array1.begin(), array1.end(), back_inserter(difference2));
    cout << "Різниця M-N: " << difference2.size() << endl;
    for (const auto &element : difference2)
    {
        cout << element << " ";
    }
    cout << endl;

    // Перетин
    vector<int> intersection;
    set_intersection(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(intersection));
    cout << "Перетин: " << intersection.size() << endl;
    for (const auto &element : intersection)
    {
        cout << element << " ";
    }
    cout << endl;

    // Об'єднання
    vector<int> unionSet;
    set_union(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(unionSet));
    cout << "Об'єднання: " << unionSet.size() << endl;
    for (const auto &element : unionSet)
    {
        cout << element << " ";
    }
    cout << endl;

    // Симетрична різниця
    vector<int> symmetricDiff;
    set_symmetric_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(symmetricDiff));
    cout << "Симетрична різниця: " << symmetricDiff.size() << endl;
    for (const auto &element : symmetricDiff)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
