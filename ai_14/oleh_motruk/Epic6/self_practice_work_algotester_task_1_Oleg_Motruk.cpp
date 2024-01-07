#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    int size_a, size_b;
    cin >> size_a;

    vector<int> array_a(size_a);

    for(int i = 0; i < size_a; i++) {
        cin >> array_a[i];
    }

    cin >> size_b;

    vector<int> array_b(size_b);
    for(int i = 0; i < size_b; i++) {
        cin >> array_b[i];
    }

    sort(array_a.begin(), array_a.end());
    sort(array_b.begin(), array_b.end());

    vector<int> result(size_a + size_b);
    auto it_diff_nm = set_difference(array_a.begin(), array_a.end(), array_b.begin(), array_b.end(), result.begin(), compare);
    result.resize(it_diff_nm - result.begin());
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> result2(size_a + size_b);
    auto it_diff_mn = set_difference(array_b.begin(), array_b.end(), array_a.begin(), array_a.end(), result2.begin(), compare);
    result2.resize(it_diff_mn - result2.begin());
    cout << result2.size() << endl;
    for(int i = 0; i < result2.size(); i++) {
        cout << result2[i] << " ";
    }
    cout << endl;

    vector<int> result3(size_a + size_b);
    auto it_inter = set_intersection(array_a.begin(), array_a.end(), array_b.begin(), array_b.end(), result3.begin(), compare);
    result3.resize(it_inter - result3.begin());
    cout << result3.size() << endl;
    for(int i = 0; i < result3.size(); i++) {
        cout << result3[i] << " ";
    }
    cout << endl;

    vector<int> result4(size_a + size_b);
    auto it_union = set_union(array_a.begin(), array_a.end(), array_b.begin(), array_b.end(), result4.begin(), compare);
    result4.resize(it_union - result4.begin());
    cout << result4.size() << endl;
    for(int i = 0; i < result4.size(); i++) {
        cout << result4[i] << " ";
    }
    cout << endl;

    vector<int> result5(size_a + size_b);
    auto it_sym_diff = set_symmetric_difference(array_a.begin(), array_a.end(), array_b.begin(), array_b.end(), result5.begin(), compare);
    result5.resize(it_sym_diff - result5.begin());
    cout << result5.size() << endl;
    for(int i = 0; i < result5.size(); i++) {
        cout << result5[i] << " ";
    }
    cout << endl;

    return 0;
}

