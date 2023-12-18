#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    do {
        cin >> N;
    } while (N<1 || N>100);
   
    vector<int> arr1(N);
    for(int a=0; a<N; a++) {
        cin >> arr1[a];
    }

    do {
        cin >> M;
    } while (M<1 || M>100);

    vector<int> arr2(M);
    for(int a=0; a<M; a++) {
        cin >> arr2[a];
    }

    vector<int> differenceNM;
    vector<int> differenceMN;
    vector<int> intersection;
    vector<int> unification;
    vector<int> symdifference;

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    set_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(differenceNM));
    set_difference(arr2.begin(), arr2.end(), arr1.begin(), arr1.end(), back_inserter(differenceMN));
    set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(intersection));
    set_union(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(unification));
    set_symmetric_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(symdifference));

    
    cout << "\n" << differenceNM.size() << endl;
    for(int element : differenceNM) {
        cout << element << " "; 
    }
    cout << endl;

    cout << "\n" << differenceMN.size() << endl;
    for(int element : differenceMN) {
        cout << element << " ";
    }
    cout << endl;

    cout << "\n" << intersection.size() << endl;
    for(int element : intersection) {
        cout << element << " ";
    }
    cout << endl;

    cout << "\n" << unification.size() << endl;
    for(int element : unification) {
        cout << element << " ";
    }
    cout << endl;

    cout << "\n" << symdifference.size() << endl;
    for(int element : symdifference) {
        cout << element << " ";
    }

    return 0;
}