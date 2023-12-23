#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
    int N;
    cin>>N;
    int k;
    cin>>k;
    set<int>st;
    for (int i = 0; i < N; i++) {
        int x;
        cin>>x;
        st.insert(x);
    }
    int len = st.size();
    vector<int>a;
    for (auto p : st) {
        a.push_back(p);
    }
    cout<<len<<endl;
    k %= len;
    for (int i = k; i < len; i++) {
        cout<<a[i]<<' ';
    }
    for (int i = 0; i < k; i++) {
        cout<<a[i]<<' ';
    }
    return 0;
}
