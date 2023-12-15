#include <iostream>
using namespace std;
int solve(){
    string s;
    getline(cin, s);
    int r=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='#'&&(i==s.size()-1||s[i+1]!='#')) r++;
    }
    return r;
}
int main(){
    int n;
    cin >> n;
    int ans = 0;
    string s;
    getline(cin, s);
    for(int i=0;i<n;i++){
        int d=solve();
        ans+=d;
    }
    cout << ans;
}