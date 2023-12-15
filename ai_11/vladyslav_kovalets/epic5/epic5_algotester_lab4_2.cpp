#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int N, M;

    // Зчитуємо розмір та елементи масиву 1
    cin >> N;
    vector<int> array1(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> array1[i];
    }

    // Зчитуємо розмір та елементи масиву 2
    cin >> M;
    vector<int> array2(M);
    for (int i = 0; i < M; i++) 
    {
        cin >> array2[i];
    }

    // Сортуємо масиви
    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());

    // Різниця N-M
    vector<int> diffNM;
    set_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(diffNM));

    // Різниця M-N
    vector<int> diffMN;
    set_difference(array2.begin(), array2.end(), array1.begin(), array1.end(), back_inserter(diffMN));

    // Перетин
    vector<int> intersection;
    set_intersection(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(intersection));

    // Об'єднання
    vector<int> unionSet;
    set_union(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(unionSet));

    // Симетрична різниця
    vector<int> symmetricDiff;
    set_symmetric_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(symmetricDiff));

    // Виведення результатів
    cout << diffNM.size() << endl;
    for (int value : diffNM) 
    {
        cout << value << " ";
    }
    cout << endl;

    cout << diffMN.size() << endl;
    for (int value : diffMN) 
    {
        cout << value << " ";
    }
    cout << endl;

    cout << intersection.size() << endl;
    for (int value : intersection) 
    {
        cout << value << " ";
    }
    cout << endl;

    cout << unionSet.size() << endl;
    for (int value : unionSet) 
    {
        cout << value << " ";
    }
    cout << endl;

    cout << symmetricDiff.size() << endl;
    for (int value : symmetricDiff) 
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
