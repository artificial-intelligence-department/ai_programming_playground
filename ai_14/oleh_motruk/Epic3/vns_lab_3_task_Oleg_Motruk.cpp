#include <iostream>
#include <cmath> 
#include <iomanip>

using namespace std;
int main(){

    double x , n , accuracy,step,result_a, an_a , sum_a, result , an , sum;
    x = 0.1;
    step = (1 - 0.1)/10;

    accuracy = 0.0001;

    for (x; x <= 1.0; x += step){
        result = 1.0;
        sum = 1.0;
        an = 1.0;
        for(int n = 1; n <= 10; n++){
            an *= -1*(pow(x,2)/(2 * n)*(2 * n - 1));
            result += an;
            sum += result;
        }
        
        result_a = 1.0;
        sum_a = 1.0;
        an_a = 1.0;
        for(int n = 1; abs(an_a) >= accuracy; n++){
             an_a *= -1*(pow(x,2))/((2 * n)*(2 * n - 1));
            result_a += an_a;
            sum_a += result_a;
        }
        double y = cos(x);
        cout <<"X: "<< x <<"\t SN: " << sum <<"\t SE: "<< sum_a << "\t Y: " << y << endl;
    }
    
    return 0;
}