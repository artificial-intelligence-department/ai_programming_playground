#include <iostream>
using namespace std;

int main(){
    long long cube's sides[5];
    for(int i=0; i<5; i++){
        cin >> cube's sides [i];
      
        if (cube's sides[i] <= 0) {
            cout << "ERROR";
            return 0;
        }
        else if(i>=1 && cube's sides[i]>cube's sides[i-1]){
            cout << "LOSS";
            return 0;
        }
    }

    cout << "WIN";
    
     return 0;
}


