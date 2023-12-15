#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N, K,n;
    vector<int> ar1;
    vector<int> ar2;
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>n;
        ar1.push_back(n);
        n=0;}
    cin>>K;
    for(int i=0; i<K; i++) {
        cin>>n;
        ar2.push_back(n);
        n=0;}
    sort(ar1.begin(), ar1.end());
    sort(ar2.begin(), ar2.end());

    vector<int> dif1;
    set_difference(ar1.begin(), ar1.end(), ar2.begin(), ar2.end(), back_inserter(dif1));
    cout<<dif1.size()<<endl;
    for (int i=0; i<dif1.size(); i++) {
         cout<<dif1[i]<<" ";
    }
    cout<<endl<<endl;
    vector<int> dif2;
    set_difference(ar2.begin(), ar2.end(), ar1.begin(), ar1.end(), back_inserter(dif2));
    cout<<dif2.size()<<endl;
    for (int i=0; i<dif2.size(); i++) {
         cout<<dif2[i]<<" "; 
    }
    cout<<endl<<endl;
    vector<int> in;
    set_intersection(ar1.begin(), ar1.end(), ar2.begin(), ar2.end(), back_inserter(in));
    cout<<in.size()<<endl;
    for (int i=0; i<in.size(); i++) {
         cout<<in[i]<<" "; 
    }
    cout<<endl<<endl;
    vector<int> uni;
    set_union(ar1.begin(), ar1.end(), ar2.begin(), ar2.end(), back_inserter(uni));
    cout<<uni.size()<<endl;
    for (int i=0; i<uni.size(); i++) {
         cout<<uni[i]<<" "; 
    }
    cout<<endl<<endl;
    vector<int> sym_dif;
    set_symmetric_difference (ar1.begin(), ar1.end(), ar2.begin(), ar2.end(), back_inserter(sym_dif));
    cout<<sym_dif.size()<<endl;
    for (int i=0; i<sym_dif.size(); i++) {
         cout<<sym_dif[i]<<" "; 
    }
    return 0;
}
