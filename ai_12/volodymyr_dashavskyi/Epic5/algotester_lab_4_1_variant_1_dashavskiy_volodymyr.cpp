#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()

{
    unsigned int N, M;
    N != 0;
    M != 0;
    cin >> N;
    vector<int> difference1, difference2, intersection, unionSet, symmetricDifference;

    vector<int> array1(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> array1[i];
    }

    cin >> M;
    vector<int> array2(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> array2[i];
    }
    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());

    set_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(difference1));

    cout << difference1.size() << endl;
    for (const auto &elem : difference1)
    {
        cout << elem << " ";
    }
    cout << endl;

    set_difference(array2.begin(), array2.end(), array1.begin(), array1.end(), back_inserter(difference2));

    cout << difference2.size() << endl;
    for (const auto &elem : difference2)
    {
        cout << elem << " ";
    }
    cout << endl;

    set_intersection(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(intersection));

    cout << intersection.size() << endl;
    for (const auto &elem : intersection)
    {
        cout << elem << " ";
    }
    cout << endl;

    set_union(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(unionSet));

    cout << unionSet.size() << endl;
    for (const auto &elem : unionSet)
    {
        cout << elem << " ";
    }
    cout << endl;

    set_symmetric_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(symmetricDifference));

    cout << symmetricDifference.size() << endl;
    for (const auto &elem : symmetricDifference)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
