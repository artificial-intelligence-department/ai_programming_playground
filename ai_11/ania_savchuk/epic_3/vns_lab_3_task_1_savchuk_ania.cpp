#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n){
    if(n>1){

        return n * factorial(n-1);
    }else{
        return 1;
    }
}

int main(){
    double epsilon, a ,b , x , k , n, an, sn, y, se;
    n = 20;
    epsilon = 0.0001;
    a = 0.1;
    b = 1;
    k = 10;
    sn = 1;
    an = 1;
    y = 0;
    se = 1;

    for (x=a; x <= b; x+=(b-a)/k ){
        
        y = exp(2*x);

        an = 1;
        sn = 1;
        for (int i = 1; i < n; i++){
            an=pow(2*x, i)/factorial(i);
            sn += an;
        }

        an = 1;
        se = 1;
        for (int i = 1; i < n ; i++){
            if (an > epsilon) {
            an=pow(2*x, i)/factorial(i);
            se += an;
            }
            else {
                break;
            }
         }
        cout << "X= " << x << "  SN= " << sn << "  SE= " << se << "  Y= " << y << endl;    
    }
    
}
