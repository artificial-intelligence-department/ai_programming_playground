#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main () {
    vector<int> U, I, D1, D2, DS;
    int n, m;

    cin >> n;
    vector<int> N(n);
    for (int i=0; i<n; i++) {
        cin >> N[i];
    }

    cin >> m;
    vector<int> M(m);
    for (int j=0; j<m; j++) {
        cin >> M[j];
    }

    sort(M.begin(), M.end());
    sort (N.begin(), N.end());
    
    set_difference(N.begin(), N.end(), M.begin(), M.end(), back_inserter(D1)); // різниця N-M
    set_difference(M.begin(), M.end(), N.begin(), N.end(), back_inserter(D2)); // M-N
    set_intersection(N.begin(), N.end(), M.begin(), M.end(), back_inserter(I)); // перетин
    set_union(N.begin(), N.end(), M.begin(), M.end(), back_inserter(U)); // об'єднання
    set_symmetric_difference(N.begin(), N.end(), M.begin(), M.end(), back_inserter(DS)); // симетрична різниця


    cout << "\n" << D1.size() << endl;
    for (auto i = D1.begin(); i!=D1.end(); i++) {
        cout << *i << " " ;
    }
    cout << endl;

    cout << "\n" << D2.size() << endl;
    for (auto i = D2.begin(); i!=D2.end(); i++) {
        cout << *i << " " ;
    }
    cout << endl;

    cout << "\n" << I.size() << endl;
    for (auto i = I.begin(); i!=I.end(); i++) {
        cout << *i << " " ;
    }
    cout << endl;

    cout << "\n" << U.size() << endl;
    for (auto i = U.begin(); i!=U.end(); i++) {
        cout << *i << " " ;
    }
    cout << endl;

    cout << "\n" << DS.size() << endl;
    for (auto i = DS.begin(); i!=DS.end(); i++) {
        cout << *i << " " ;
    }
    cout << endl;

}