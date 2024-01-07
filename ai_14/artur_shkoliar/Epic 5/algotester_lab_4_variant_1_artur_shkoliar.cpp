#include <iostream>
#include <algorithm>

int main() {
    using namespace std;

    int N, M;

    cin >> N;
    int arrayN[100]; 
    for (int i = 0; i < N; ++i) 
    {
        cin >> arrayN[i];
    }

    cin >> M;
    int arrayM[100];
    for (int i = 0; i < M; ++i) 
    {
        cin >> arrayM[i];
    }

    sort(arrayN, arrayN + N);
    sort(arrayM, arrayM + M);

    int differenceNM[100];
    auto it_diff_NM = set_difference(arrayN, arrayN + N, arrayM, arrayM + M, differenceNM);
    int size_diff_NM = distance(differenceNM, it_diff_NM);

    cout << size_diff_NM << endl;

    for (int i = 0; i < size_diff_NM; ++i) 
    {
        cout << differenceNM[i] << " ";
    }
    cout << endl;

    int differenceMN[100];
    auto it_diff_MN = set_difference(arrayM, arrayM + M, arrayN, arrayN + N, differenceMN);
    int size_diff_MN = distance(differenceMN, it_diff_MN);

    cout << size_diff_MN << endl;
    for (int i = 0; i < size_diff_MN; ++i) 
    {
        cout << differenceMN[i] << " ";
    }

    cout << endl;

    int intersection[100];
    auto it_intersection = set_intersection(arrayN, arrayN + N, arrayM, arrayM + M, intersection);
    int size_intersection = distance(intersection, it_intersection);

    cout << size_intersection << endl;

    for (int i = 0; i < size_intersection; ++i) 
    {
        cout << intersection[i] << " ";
    }

    cout << endl;

    int Union[200];
    auto it_union = set_union(arrayN, arrayN + N, arrayM, arrayM + M, Union);
    int size_union = distance(Union, it_union);

    cout << size_union << endl;

    for (int i = 0; i < size_union; ++i) 
    {
        cout << Union[i] << " ";
    }

    cout << endl;

    int symmetricDifference[200];
    auto it_symmetric_diff = set_symmetric_difference(arrayN, arrayN + N, arrayM, arrayM + M, symmetricDifference);
    int size_symmetric_diff = distance(symmetricDifference, it_symmetric_diff);

    cout << size_symmetric_diff << endl;

    for (int i = 0; i < size_symmetric_diff; ++i) 
    {
        cout << symmetricDifference[i] << " ";
    }
    
    cout << endl;

    return 0;
}
