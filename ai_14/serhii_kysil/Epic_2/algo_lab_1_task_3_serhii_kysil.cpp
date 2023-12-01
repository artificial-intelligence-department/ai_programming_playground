#include <iostream>
using namespace std;
int main(){
    long long a[5];
    for (int i = 0; i < 5; i++) {
        cout<< "Enter the length of the edge of the "<< i+1 <<" cube:\n ";
        cin>>a[i];
        if (a[i] <=0){
            cout<<"ERROR";
            exit(0);
        }
        else if (a[i-1] < a[i]){
            cout<< "LOSS";
            exit(0);
        }
    }
    cout<<"WIN";
    return 0;
}