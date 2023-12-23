#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void printSet(const set<int>& s) {
    cout << s.size() << endl;
    for (int elem : s) {
        cout << elem << ' ';
    }
    cout << endl << endl;  // Add newline character
}

void performSetOperations(const set<int>& set1, const set<int>& set2) {
    set<int> differenceN_M, differenceM_N, intersection, unionSet, symmetricDifference;

    // Difference N - M
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(differenceN_M, differenceN_M.begin()));
    printSet(differenceN_M);

    // Difference M - N
    set_difference(set2.begin(), set2.end(), set1.begin(), set1.end(), inserter(differenceM_N, differenceM_N.begin()));
    printSet(differenceM_N);

    // Intersection
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(intersection, intersection.begin()));
    printSet(intersection);

    // Union
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(unionSet, unionSet.begin()));
    printSet(unionSet);

    // Symmetric Difference
    set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(symmetricDifference, symmetricDifference.begin()));
    printSet(symmetricDifference);
}

int main() {
    int N, M;

    cin >> N;
    set<int> setN;
    for (int i = 0; i < N; i++) {
        int element;
        cin >> element;
        setN.insert(element);
    }

    cin >> M;
    set<int> setM;
    for (int i = 0; i < M; i++) {
        int element;
        cin >> element;
        setM.insert(element);
    }

    performSetOperations(setN, setM);

    return 0;
}
