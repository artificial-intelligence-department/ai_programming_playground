#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x, a, y;
    a = 1;
    x = 0.5;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter a: ";
    cin >> a;
    if(1<= x && x <= 8){
        //x = 0.5;
        if (2 <= a && a <= 10){
            //a = 1;
            if(a > x){
                y = pow(a,2) + x;
                cout << y << endl;
            }else if(a == x){
                y = pow(a, 2);
                cout << y << endl;
            }else if(a < x){
                y = pow(a,2) - x;
                cout << y << endl;
            }
        }else{
            cout << "Error!";
        }        
    }else{
        cout << "Error!";
    }
}