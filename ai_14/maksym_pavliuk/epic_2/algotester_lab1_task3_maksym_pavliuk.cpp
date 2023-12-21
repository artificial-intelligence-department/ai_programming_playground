#include<iostream>
using namespace std;

int main(){
    long long int a[5];

    //printf("\nInput a[0]");
    cin >> a[0];
    if (a[0] <= 0){
        cout << "ERROR";
        return 0;
    }

    for(int i=1; i<5; i++){
        //printf("\nInput a[%i]: ", i);
        cin >> a[i];
        if (a[i] <= 0){
            cout << "ERROR";
            return 0;
        } else if(a[i] > a[i-1]){
            cout << "LOSS";
            return 0;
        }
    }
    cout << "WIN";

    return 0;
}
