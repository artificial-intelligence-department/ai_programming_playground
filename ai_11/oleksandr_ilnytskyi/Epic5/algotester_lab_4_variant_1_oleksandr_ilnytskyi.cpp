#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> nums1(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums1[i];
    }

    cin >> m;
    vector<int> nums2(m);
    for (int i = 0; i < m; ++i) {
        cin >> nums2[i];
    }

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> diff12;
    set_difference(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(diff12));
    cout << diff12.size() << endl;
    for (int num : diff12) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> diff21;
    set_difference(nums2.begin(), nums2.end(), nums1.begin(), nums1.end(), back_inserter(diff21));
    cout << diff21.size() << endl;
    for (int num : diff21) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> intersection;
    set_intersection(nums2.begin(), nums2.end(), nums1.begin(), nums1.end(), back_inserter(intersection));
    cout << intersection.size() << endl;
    for (int num : intersection) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nunion;
    set_union(nums2.begin(), nums2.end(), nums1.begin(), nums1.end(), back_inserter(nunion));
    cout << nunion.size() << endl;
    for (int num : nunion) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> sym_dif;
    set_symmetric_difference(nums2.begin(), nums2.end(), nums1.begin(), nums1.end(), back_inserter(sym_dif));
    cout << sym_dif.size() << endl;
    for (int num : sym_dif) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
