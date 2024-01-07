#include <iostream>
#include <cmath>
using namespace std;

    double func_for_y(double x) {
        double y = 1/4 *(pow (x, 2) - pow (M_PI, 2)/3 );
        return y;

}

double func_for_sum(int n, double x){

    double sum = 0;
    for(int b = 0; b < n; b++){
double num1 = pow(-1, b+1) + cos(x*(b+1));
sum+= num1/pow(b+1, 2);
    }
    return sum;

}
int main (){
    double y;
    for (double x= M_PI/5; x<=M_PI; x+=(M_PI-(M_PI/5))*10){
    cout << "x =" << x << " ";
    cout << "sn = ";
     for(int i = 1; i <= 20; i++){

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










