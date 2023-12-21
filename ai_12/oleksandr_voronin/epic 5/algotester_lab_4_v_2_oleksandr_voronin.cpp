#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    
    int size,k;
    cin >> size >> k;
    vector<int> N;
    for(int i=0;i<size;i++){
        int element;
        cin >> element;
        N.push_back(element);
        
    }
    sort(N.begin(), N.end());
    auto x = unique(N.begin(), N.end());
    N.erase(x,N.end());
    if(k > N.size()){
        k = k % N.size();
    }
    
    
    rotate(N.begin(), N.begin() + k, N.end());
    cout<< N.size()<<endl;
    for(int i = 0;i <N.size();i++){
        cout << N[i]<<" ";
    }
    cout <<endl;
}