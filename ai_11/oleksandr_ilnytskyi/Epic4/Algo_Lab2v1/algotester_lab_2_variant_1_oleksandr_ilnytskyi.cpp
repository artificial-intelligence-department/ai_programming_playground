#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long min_dist(vector<long long> nums, long long min) {
    vector<long long> copied = nums;
    long long minVal = copied[min];
    for (int i = 0; i < copied.size(); i++) {
        if (copied[i] == minVal) {
            copied.erase(copied.begin() + i);
            --i;
        }
    }
    return *min_element(copied.begin(), copied.end()) - minVal;
}

long long max_dist(vector<long long> nums, long long max) {
    vector<long long> copied = nums;
    long long maxVal = copied[max];
    for (int i = 0; i < copied.size(); i++) {
        if (copied[i] == maxVal) {
            copied.erase(copied.begin() + i);
            --i;
        }
    }
    return maxVal - *max_element(copied.begin(), copied.end());
}

int main() {
    unsigned long long length = 0;
    vector<long long> nums;
    cin >> length;
    if (length == 1) {
        cout << 0;
        return 0;
    }

    long long min_occasions = 0;
    long long max_occasions = 0;

    for (int i = 0; i < length; i++) {
        long long num = 0;
        cin >> num;
        nums.push_back(num);
    }

    long long min = distance(nums.begin(), min_element(nums.begin(), nums.end()));
    long long max = distance(nums.begin(), max_element(nums.begin(), nums.end()));

    for (int i = 0; i < length; i++) {
        if (nums[i] == nums[min]) {
            min_occasions += 1;
        }
        if (nums[i] == nums[max]) {
            max_occasions += 1;
        }
    }

    if (min_occasions > max_occasions && max_occasions == 1) {
        nums.erase(nums.begin() + max);
        cout << *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
    }
    else if (max_occasions > min_occasions && min_occasions == 1) {
        nums.erase(nums.begin() + min);
        cout << *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
    }
    else {
        if (max_dist(nums, max) > min_dist(nums, min)) {
            nums.erase(nums.begin() + max);
        }
        else {
            nums.erase(nums.begin() + min);
        }
        cout << *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
    }
}
