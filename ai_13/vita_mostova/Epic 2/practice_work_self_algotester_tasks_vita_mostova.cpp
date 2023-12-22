#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of coins\n";
    cin>>n;
    if(n<1 || n>100000){
        cout<<"wrong input";
    }else {
    int totalsum=0;
    for(int i=1;i<=n;i++){
        int coinValue;
       cout<<"Enter the values of coins\n";
        cin>>coinValue;
        if(coinValue==1 || coinValue == 2){
                totalsum+=coinValue;
                       } else{
                cout<<"wrong input";
                return 0;
             }
                }
    if(totalsum % 2==0){
        cout<<"YES";
    }else if(totalsum % 2==1){
        cout<<"NO";}
         
    }
    return 0;
}
