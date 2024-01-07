#include <iostream>
#include <vector>
#include <algorithm>
int main(){
using namespace std;
vector<int> massive;
int n, k, b;
cin >> n >> k;
for(int i = 0; i <n; i++){
    cin >> b;
 massive.push_back(b); 
}

sort(massive.begin(), massive.end());
auto it = unique(massive.begin(), massive.end());
massive.erase(it, massive.end());

rotate(massive.begin(), massive.begin() + k % massive.size(), massive.end());
cout << massive.size() << endl;
for(int j = 0; j < massive.size(); j++){
    cout << massive[j] << " ";
}


    return 0;
}
