#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector <int> b(m);
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector <int> diff1;
    
    // 1. Різницю N-M
    set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(diff1));
    cout << diff1.size() << endl;
    for (int i = 0; i < diff1.size(); ++i) {
        cout << diff1[i] << " ";
    }
    cout << endl;

    vector <int> diff2;

    // 2. Різницю M-N
    set_difference(b.begin(), b.end(), a.begin(), a.end(), back_inserter(diff2));
    cout << diff2.size() << endl;
    for (int i = 0; i < diff2.size(); ++i) {
        cout << diff2[i] << " ";
    }
    cout << endl;
   
    vector <int> crossing;

    // 3. Їх перетин
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(crossing));
    cout << crossing.size() << endl;
    for (int i = 0; i < crossing.size(); ++i) {
        cout << crossing[i] << " ";
    }
    cout << endl;
   
    vector <int> association;

    // 4. Їх об'єднання
    set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(association));
    cout << association.size() << endl;
    for (int i = 0; i < association.size(); ++i) {
        cout << association[i] << " ";
    }
    cout << endl;
  
    vector <int> symmdiff;

    // 5. Їх симетричну різницю
    set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(symmdiff));
    cout << symmdiff.size() << endl;
    for (int i = 0; i < symmdiff.size(); ++i) {
        cout << symmdiff[i] << " ";
    }
    cout << endl;

    return 0;
}
    