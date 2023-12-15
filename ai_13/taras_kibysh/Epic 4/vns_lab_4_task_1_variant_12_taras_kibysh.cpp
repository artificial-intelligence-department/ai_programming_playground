#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
int main(){
    using namespace std;
    int n;
    double sum = 0;
    cin >> n;
    vector<int> massive;
    cout << "random massive:" << endl;
    for(int i = 0;i<n; i++){
     massive.push_back(rand() % 100);
    cout << massive[i] << " ";
    }
    cout << endl;
    auto max = max_element(massive.begin(),massive.end());
    auto min = min_element(massive.begin(), massive.end());
    iter_swap(max,min);
    cout << "massive with swaped min and max elements:" << endl;
    for(int i = 0;i<n; i++){
    cout << massive[i] << " ";
    sum += massive[i];
    }

    cout << endl;
    sum = sum/massive.size();
    cout << "the avarage number is:" << sum;

     cout << endl;
    for(int j = 0; j<massive.size();j++){
        if(massive[j]>sum*1.1){
        massive.erase(massive.begin() + j);
        j--;
        }

    }
    cout << "massive with deleted elements:" << endl;
     for(int i = 0;i<massive.size(); i++)
    cout << massive[i] << " ";




return 0;

}