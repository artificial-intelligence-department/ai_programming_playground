#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Inputs part
    vector<int> all;
    int len1 = 0;
    cin >> len1;
    vector<int> nums1;
    for (int i = 0; i < len1; i++) {
        int num = 0;
        cin >> num;
        nums1.push_back(num);
        all.push_back(num);
    }
    int len2 = 0;
    cin >> len2;
    vector<int> nums2;
    for (int i = 0; i < len2; i++) {
        int num = 0;
        cin >> num;
        nums2.push_back(num);
        all.push_back(num);
    }

    // Main part
    vector<int> shared;
    vector<int> unique;

    for (int x = 0; x < len1; x++) {
        bool isUnique = true;
        for (int y = 0; y < len2; y++) {
            if (nums1[x] == nums2[y]) {
                isUnique = false;
            }
        }
        if (isUnique) {
            unique.push_back(nums1[x]);
        }
        else {
            shared.push_back(nums1[x]);
        }
    }
    for (int y = 0; y < len2; y++) {
        bool isUnique = true;
        for (int x = 0; x < len1; x++) {
            if (nums2[y] == nums1[x]) {
                isUnique = false;
            }
        }
        if (isUnique) {
            unique.push_back(nums2[y]);
        }
        else {
            shared.push_back(nums2[y]);
        }
    }

    cout << shared.size()/2 << endl;
    cout << all.size()-shared.size()/2;
    return 0;
}
