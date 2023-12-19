#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void findNums(const vector<string>& table, const int& r, const int& c, const int& n){
    if(table[r][c] != '0'){
        cout << 1 << endl << table[r][c] << endl << endl;
        return;
    }
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 1);
    //row
    for(size_t i = 0; i < n; i++){
        if(table[r][i] != '0' && find(nums.begin(), nums.end(), table[r][i] - '0') != nums.end()) {
            auto it = find(nums.begin(), nums.end(), table[r][i] - '0');
            nums.erase(it);
        }
    }
    //col
    for(size_t i = 0; i < n; i++){
        if(table[i][c] != '0' && find(nums.begin(), nums.end(), table[i][c] - '0') != nums.end()) {
            auto it = find(nums.begin(), nums.end(), table[i][c] - '0');
            nums.erase(it);
        }
    }
    cout << nums.size() << endl;
    if(nums.empty()) return;
    for(auto& i : nums) cout << i << " ";
    cout << endl << endl;
}

int main() {
    int n;
    cin >> n;
    vector<string> table (n);
    for(auto& i : table){
        cin >> i;
    }
    int q;
    cin >> q;
    for(size_t i = 0; i < q; i++){
        int r, c;
        cin >> r >> c;
        r--; c--;
        findNums(table, r, c, n);
    }
    return 0;
}

