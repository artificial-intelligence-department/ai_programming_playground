#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int>a (N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    auto new_a = unique(a.begin(),a.end());
    a.erase(new_a, a.end());

    if(K>a.size())
        K%=a.size();
    rotate(a.begin(), a.begin()+K, a.end());
    
    cout << a.size() << endl;
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    
    return 0;
}