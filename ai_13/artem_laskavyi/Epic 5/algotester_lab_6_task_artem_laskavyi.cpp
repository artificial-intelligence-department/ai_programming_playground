#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

bool sortZA(char a, char b){
    return a > b;
}

int main(){

    int n, k, m = 0;
    cin >> n >> k;
    string t, res;
    vector<string> s;
    unordered_map<string, int> map;
    
    for (int i = 0; i < n; i++) {
        cin >> t;
        transform(t.begin(), t.end(), t.begin(), ::tolower);
        s.push_back(t);
        map[t]++;
    }

    for (int i = 0; i < n; i++) {
        int count = map[s[i]];
        if (count >= k) {
            m += count;
            res += s[i];
        }
    }
    
    sort(res.begin(), res.end());
    auto last = unique(res.begin(), res.end());
    res.erase(last, res.end());
    
    sort(res.begin(), res.end(), sortZA);
    
    if(m >= k){
        cout << res.size() << endl;
        for (auto ch : res){
            cout << ch << " ";
        }
    }else{
        cout << "Empty!";
    }
    
    return 0;
}
