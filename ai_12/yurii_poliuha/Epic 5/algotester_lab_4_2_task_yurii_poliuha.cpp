#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int LimitOfArray(){
    int a;
    bool review = false;
    cin >> a;

    while(review == false){
        if(a >= 0 && a <= 100) review = true;
        else cin >> a;
    }
    return a;
}

int Limit(){
    int a;
    bool review = false;
    cin >> a;

    while(review == false){
        if(a >= 1 && a <= 1000) review = true;
        else cin >> a;
    }
    return a;
}

int main(){
    int N, K;
    N = Limit();
    K = Limit();
    vector<int> array(N);
    
    for(int i = 0; i < array.size(); i++){
        array[i] = LimitOfArray();
    }

    sort(array.begin(), array.end());
    auto repeated_elements = unique(array.begin(), array.end());
    array.erase(repeated_elements, array.end());
    while(true){
        if(K >= array.size()) K -= array.size();
        else break;
    }
    rotate(array.begin(), array.begin() + K, array.end());

    cout << array.size() << endl;
    for(int i = 0; i < array.size(); i++){
        cout << array[i] << "  ";
    }
    return 0;
}