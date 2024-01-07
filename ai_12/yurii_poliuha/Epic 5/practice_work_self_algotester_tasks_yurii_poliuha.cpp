#include <iostream>
#include <cmath>
using namespace std;

long long Review(){
    long long a;
    bool review = false;
    cin >> a;
    while(review == false){
        if(a >= -pow(10, 12) && a <= pow(10, 12)) review = true;
        else cin >> a;
    }
    return a;
}

int main(){
    int Size = 5;
    int count = 0;
    long long review;
    long long a[Size];

    for(int i = 0; i < Size; i++){
        a[i] = Review();
    }
    
    review = a[0];
    for(int i = 1; i < Size; i++){
        if(review <= 0 || a[i] <= 0){
            cout << "ERROR";
            break;
        }
        if(review > 0 && a[i] > 0 && review < a[i]){
            cout << "LOSS";
            break;
        }
        if(review > 0 && a[i] > 0 && review >= a[i]) count++;
        review = a[i];
    }

    if(count == 4) cout << "WIN";

    return 0;
}