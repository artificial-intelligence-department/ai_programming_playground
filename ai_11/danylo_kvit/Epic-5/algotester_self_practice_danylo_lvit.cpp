#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a;
    vector<int> a0;
    vector<int> a1;
    vector<int> a2;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a % 3 == 0) if(find(a0.begin(),a0.end(),a)==a0.end()) a0.push_back(a);
        if (a % 3 == 1) if(find(a1.begin(),a1.end(),a)==a1.end()) a1.push_back(a);
        if (a % 3 == 2) if(find(a2.begin(), a2.end(),a)==a2.end()) a2.push_back(a);
    }
    sort(a0.begin(),a0.end());
    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end());
    reverse(a1.begin(),a1.end());
    cout << a0.size()+a1.size()+a2.size() << '\n';
    for(int i:a0) cout << i << ' ';
    for(int i:a1) cout << i << ' ';
    for(int i:a2) cout << i << ' ';
}