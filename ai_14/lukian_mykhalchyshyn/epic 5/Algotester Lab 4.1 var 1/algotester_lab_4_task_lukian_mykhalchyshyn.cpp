#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;

    cin >> N;

    int* arr1 = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr1[i];
    }

    cout << endl;
    cin >> M;

    int* arr2 = new int[M];
    for (int i = 0; i < M; i++)
    {
        cin >> arr2[i];
    }

    sort(arr1, arr1 + N);
    sort(arr2, arr2 + M);

    int* difference_1 = new int[max(N, M)]; 
    int* end_difference_1 = set_difference (arr1, arr1 + N, arr2, arr2 + M, difference_1);
    int size_1 = end_difference_1 - difference_1;

    int* difference_2 = new int[max(N, M)]; 
    int* end_difference_2 = set_difference (arr2, arr2 + M, arr1, arr1 + N, difference_2);
    int size_2 = end_difference_2 - difference_2;

    int* crossing = new int[min(N, M)]; 
    int* end_crossing = set_intersection (arr1, arr1 + N, arr2, arr2 + M, crossing);
    int size_3 = end_crossing - crossing;

    int* unification = new int[N + M]; 
    int* end_unification = set_union (arr1, arr1 +N, arr2, arr2 + M, unification);
    int size_4 = end_unification - unification;

    int* symmetrical_difference = new int[N + M]; 
    int* end_symmetrical_difference = set_symmetric_difference (arr1, arr1 +N, arr2, arr2 + M, symmetrical_difference);
    int size_5 = end_symmetrical_difference - symmetrical_difference;

    cout << endl << size_1 << endl;
    for (int i = 0; i < size_1; i++)
    {
        cout << difference_1[i] << " ";
    }

    cout << endl << endl << size_2 << endl;
    for (int i = 0; i < size_2; i++)
    {
        cout << difference_2[i] << " ";
    }

    cout << endl << endl << size_3 << endl;
    for (int i = 0; i < size_3; i++)
    {
        cout << crossing[i] << " ";
    }

    cout << endl << endl << size_4 << endl;
    for (int i = 0; i < size_4; i++)
    {
        cout << unification[i] << " ";
    }

    cout << endl << endl << size_5 << endl;
    for (int i = 0; i < size_5; i++)
    {
        cout << symmetrical_difference[i] << " ";
    }

    delete []arr1;
    delete []arr2;
    delete []difference_1;
    delete []difference_2;
    delete []crossing;
    delete []unification;
    delete []symmetrical_difference;

    return 0;
}
