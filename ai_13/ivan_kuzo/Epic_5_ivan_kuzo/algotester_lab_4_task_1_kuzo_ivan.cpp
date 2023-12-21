#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void difference(vector<int>& N, vector<int>& M) {
    sort(N.begin(), N.end());
    sort(M.begin(), M.end());

    vector<int> differenceNM;
    set_difference(N.begin(), N.end(), M.begin(), M.end(), back_inserter(differenceNM));
    cout << differenceNM.size() << endl;
    for (const auto& b : differenceNM)
        cout << b << " ";
    cout << endl;
}

void union_arr(vector<int>& N, vector<int>& M) {
    sort(N.begin(), N.end());
    sort(M.begin(), M.end());

    vector<int> unionNM;
    set_union(N.begin(), N.end(), M.begin(), M.end(), back_inserter(unionNM));
    cout << unionNM.size() << endl;
    for (const auto& b : unionNM)
        cout << b << " ";
    cout << endl;
}

void intersection_arr(vector<int>& N, vector<int>& M) {
    sort(N.begin(), N.end());
    sort(M.begin(), M.end());

    vector<int> intersectionNM;
    set_intersection(N.begin(), N.end(), M.begin(), M.end(), back_inserter(intersectionNM));
    cout << intersectionNM.size() << endl;
    for (const auto& b : intersectionNM)
        cout << b << " ";
    cout << endl;
}

void symmetrical_diff(vector<int>& N, vector<int>& M) {
    sort(N.begin(), N.end());
    sort(M.begin(), M.end());

    vector<int> intersectionNM;
    set_intersection(N.begin(), N.end(), M.begin(), M.end(), back_inserter(intersectionNM));

    vector<int> differ;
    set_symmetric_difference(N.begin(), N.end(), M.begin(), M.end(), back_inserter(differ));
    cout << differ.size() << endl;
    for (const auto& d : differ)
        cout << d << " ";
    cout << endl;
}

int main() {
    vector<int> N_arr;
    vector<int> M_arr;

    int N = 0;
    cin >> N;
    int ni = 0;
    for (int i = 0; i < N; i++) {
        cin >> ni;
        N_arr.push_back(ni);
    }

    int M = 0;
    cin >> M;
    int mi = 0;
    for (int i = 0; i < M; i++) {
        cin >> mi;
        M_arr.push_back(mi);
    }

    difference(N_arr, M_arr);
    cout << endl;
    difference(M_arr, N_arr);
    cout << endl;
    intersection_arr(N_arr, M_arr);
    cout << endl;
    union_arr(N_arr, M_arr);
    cout << endl;
    symmetrical_diff(N_arr, M_arr);

    return 0;
}