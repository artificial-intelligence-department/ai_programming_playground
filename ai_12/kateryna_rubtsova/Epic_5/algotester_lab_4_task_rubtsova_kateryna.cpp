#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    
    cin >> N;
    vector<int> array1(N);
    for (int i = 0; i < N; ++i) {
        cin >> array1[i];
    }

    cin >> M;
    vector<int> array2(M);
    for (int i = 0; i < M; ++i) {
        cin >> array2[i];
    }

    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());

    vector<int> differenceNM;
    set_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(differenceNM));
    vector<int> differenceMN;
    set_difference(array2.begin(), array2.end(), array1.begin(), array1.end(), back_inserter(differenceMN));
    vector<int> intersection;
    set_intersection(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(intersection));
    vector<int> unionSet;
    set_union(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(unionSet));
    vector<int> symmetricDifference;
    set_symmetric_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(symmetricDifference));

    cout << differenceNM.size() << endl;
    for(int i = 0; i< differenceNM.size(); i++){
        cout << differenceNM[i] << " ";
    }
    cout << endl;
    cout << differenceMN.size() << endl;
    for(int i = 0; i< differenceMN.size(); i++){
        cout << differenceMN[i] << " ";
    }
    cout << endl;
    cout << intersection.size() << endl;
    for(int i = 0; i< intersection.size(); i++){
        cout << intersection[i] << " ";
    }
    cout << endl;
    cout << unionSet.size() << endl;
    for(int i = 0; i< unionSet.size(); i++){
        cout << unionSet[i] << " ";
    }
    cout << endl;
    cout << symmetricDifference.size() << endl;
    for(int i = 0; i< symmetricDifference.size(); i++){
        cout << symmetricDifference[i] << " ";
    }
    cout << endl;

    return 0;
}