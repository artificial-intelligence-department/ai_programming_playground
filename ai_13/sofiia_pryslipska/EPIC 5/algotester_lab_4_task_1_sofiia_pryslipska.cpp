#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> N, M;


void printVec(vector<int> myVec){
    cout << myVec.size() << endl;
    for (int i = 0; i < myVec.size(); i++){
        cout << myVec[i] << " ";
    }
    cout << endl << endl;
}


int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        N.push_back(num);
    }

    cin >> m;
    for (int i=0; i<m; i++){
        int num;
        cin >> num;
        M.push_back(num);
    }

    sort(N.begin(), N.end());
    sort(M.begin(), M.end());

    vector<int> result1;
    set_difference(N.begin(), N.end(), M.begin(), M.end(), back_inserter(result1));
    printVec(result1);

    vector<int> result2;
    set_difference(M.begin(), M.end(), N.begin(), N.end(), back_inserter(result2));
    printVec(result2);

    vector<int> result3;
    set_intersection(N.begin(), N.end(), M.begin(), M.end(), back_inserter(result3));
    printVec(result3);

    vector<int> result4;
    set_union(N.begin(), N.end(), M.begin(), M.end(), back_inserter(result4));
    printVec(result4);

    vector<int> result5;
    set_symmetric_difference(N.begin(), N.end(), M.begin(), M.end(), back_inserter(result5));
    printVec(result5);

    return 0;
}














