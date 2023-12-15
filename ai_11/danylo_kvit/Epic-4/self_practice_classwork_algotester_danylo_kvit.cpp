#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    cin >> n;
    for(int i=0;i<n;i++){
        int input;
        cin >> input;
        a.push_back(input);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int input;
        cin >> input;
        b.push_back(input);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0;
    int j=0;
    int ans=0;
    while(i<n&&j<m){
        if(a[i]==b[j]){
            c.push_back(a[i]);
            ans++;
            i++;
            j++;
            continue;
        }
        if(a[i]>b[j]){
            c.push_back(b[j]);
            j++;
        }
        if(a[i]<b[j]){
            c.push_back(a[i]);
            i++;
        }
    }
    cout << ans << '\n';
    cout << c.size()+n-i+m-j << '\n';

}