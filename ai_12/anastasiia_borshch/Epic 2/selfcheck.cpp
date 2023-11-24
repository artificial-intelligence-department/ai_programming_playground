#include <iostream>

using namespace std;
int main() {
    int n , money = 0;
    cin >> n;

    while(n>0){
        money += 1;
        if (n>=500){
            n-=500;
        }else if(n>=200){
            n-=200;
        }else if(n>=100){
            n-=100;
        }else if(n>=50){
            n-=50;
        }else if(n>=20){
            n-=20;
        }else if(n>=10){
            n-=10;
        }else if(n>=5){
            n-=5;
        }else if(n>=2){
            n-=2;
        }else if(n>=1){
            n-=1;
        }
        
    }
    cout<<money<<endl;
    return 0;
}
