#include <iostream>
#include <vector>
using namespace std;

int Review(){
    int a;
    bool review = false;
    cin >> a;
    while(review == false){
        if(a >= 1 && a <= 1000) review = true;
        else cin >> a;
    }
    return a;
}

int Review_Array(){
    int a;
    bool review = false;
    cin >> a;
    while(review == false){
        if(a >= 0 && a <= 100) review = true;
        else cin >> a;
    }
    return a;
}

int main(){
    int N, K;
    N = Review();
    K = Review();

    vector<int> array(N);
    for(int i = 0; i < array.size(); i++){
        array[i] = Review_Array();
    }

    for(int i = 1; i < array.size(); i++){
        int temp;
        for(int j = 0; j < i; j++){
            if(array[i] < array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    for(int i = 1; i < array.size(); i++){
        for(int j = 0; j < i; j++){
            if(array[i] == array[j]) array[j] = -1;
        }
    }

    vector<int> new_array;
    for(int i = 0; i < array.size(); i++){
        if(array[i] > -1) new_array.push_back(array[i]); 
    }

    while(true){
        if(K >= new_array.size()) K -= new_array.size();
        else break;
    }

    cout << new_array.size() << endl;
    for(int i = K; i < new_array.size(); i++){
        cout << new_array[i] << "  ";
    }
    for(int i = 0; i < K; i++){
        cout << new_array[i] << "  ";
    }
    return 0;
}