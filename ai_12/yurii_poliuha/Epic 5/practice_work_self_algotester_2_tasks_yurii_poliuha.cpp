#include <iostream>
using namespace std;

int Func(){
    int a;
    bool review = false;
    cin >> a;
    while(review == false){
        if(a >= 1 && a <= 100) review = true;
        else cin >> a;
    }
    return a;
}

int main(){
    int n, m;
    n = Func();
    m = Func();
    if((m * n) % 2 == 0) cout << "Dragon";
    else if((m * n) % 2 == 1) cout << "Imp";
    return 0;
}