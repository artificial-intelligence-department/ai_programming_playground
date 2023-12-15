#include <iostream>
#include <cmath>
using namespace std;
double func_for_y(double x){
    
    double y = -0.5 * log1pf(-2 * x * 0.5 + pow(x, 2));
    return y;
}
double func_for_sum(int n, double x){
    
    double sum = 0;
    for(int b = 0; b < n; b++){
        double num1 = pow(x, (b + 1)) * cos((b + 1) * (M_PI / 3));
        sum += num1/(b+1); 
    }
   return sum;
}
int main(){
    double y;
    for(double x =0.10; x<=0.80; x+=0.0045){
        cout << "x =" << x << " ";
        cout << "sn = ";
        for(int i = 1; i <= 35; i++){
        double sum = func_for_sum(i, x);
        printf("%0.4f", sum);
        break;
        }
        cout << " " << "y = ";
        y = func_for_y(x);
        printf("%0.4f", y);
        cout << endl;
    }
    return 0;
}