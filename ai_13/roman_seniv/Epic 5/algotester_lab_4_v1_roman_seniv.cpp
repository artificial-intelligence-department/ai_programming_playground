#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void printVector(const vector<int>& vec) {
    cout << vec.size() << endl;
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl << endl;
}

int main() {
    int N, M, n;
    vector<int> ar1;
    vector<int> ar2;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n;
        ar1.push_back(n);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> n;
        ar2.push_back(n);
    }

    sort(ar1.begin(), ar1.end());
    sort(ar2.begin(), ar2.end());

    vector<int> dif1;
    set_difference(ar1.begin(), ar1.end(), ar2.begin(), ar2.end(), back_inserter(dif1));
    printVector(dif1);

    vector<int> dif2;
    set_difference(ar2.begin(), ar2.end(), ar1.begin(), ar1.end(), back_inserter(dif2));
    printVector(dif2);

    vector<int> in;
    set_intersection(ar1.begin(), ar1.end(), ar2.begin(), ar2.end(), back_inserter(in));
    printVector(in);

    vector<int> uni;
    set_union(ar1.begin(), ar1.end(), ar2.begin(), ar2.end(), back_inserter(uni));
    printVector(uni);

    vector<int> sym_dif;
    set_symmetric_difference(ar1.begin(), ar1.end(), ar2.begin(), ar2.end(), back_inserter(sym_dif));
    printVector(sym_dif);

    return 0;
}