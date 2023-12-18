#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void deleteandrotate(vector<int> &numbers , int k){

    sort(numbers.begin() , numbers.end());
    numbers.erase(unique(numbers.begin() , numbers.end()) , numbers.end());

    k = k % numbers.size();
    rotate(numbers.begin(), numbers.begin() + k, numbers.end());

    cout << numbers.size() << endl;

    for(int i = 0; i < numbers.size(); i++){
        cout << numbers[i] << " ";
    }
}

int main(){
    int n , k;

    cin >> n >> k;
    vector<int> numbers(n);
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }

    deleteandrotate(numbers , k);

    return 0;
}