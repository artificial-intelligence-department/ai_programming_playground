#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end()); // Відсортувати масив a
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end()); // Відсортувати масив b

    // Різниця N-M
    vector<int> diff1;
    set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(diff1));
    cout << diff1.size() << endl;
    for (int i = 0; i < diff1.size(); i++) {
        cout << diff1[i] << " ";
    }
    cout << endl;

    // Різниця M-N
    vector<int> diff2;
    set_difference(b.begin(), b.end(), a.begin(), a.end(), back_inserter(diff2));
    cout << diff2.size() << endl;
    for (int i = 0; i < diff2.size(); i++) {
        cout << diff2[i] << " ";
    }
    cout << endl;

    // Перетин
    vector<int> intersect;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(intersect));
    cout << intersect.size() << endl;
    for (int i = 0; i < intersect.size(); i++) {
        cout << intersect[i] << " ";
    }
    cout << endl;

    // Об'єднання
    vector<int> unite;
    set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(unite));
    cout << unite.size() << endl;
    for (int i = 0; i < unite.size(); i++) {
        cout << unite[i] << " ";
    }
    cout << endl;

    // Симетрична різниця
    vector<int> sym_diff;
    set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(sym_diff));
    cout << sym_diff.size() << endl;
    for (int i = 0; i < sym_diff.size(); i++) {
        cout << sym_diff[i] << " ";
    }
    cout << endl;

    return 0;
}