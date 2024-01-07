#include <iostream>
#include <cmath>
#include <cstdarg>

using namespace std;

void result(int count, ...){
    #include <cmath>

    double pi = 3.14159265358979323846;
    va_list args;
    va_start(args, count);
    float x, y, a, b;
    for(int i = 0; i < count; i++){
        double val = va_arg(args, double);
        if(i == 0){
            x = val;
        }
        else if(i == 1){
            y = val;
        }
        else if(i == 2){
            a = val;
        }
        else if(i == 3){
            b = val;
        }
    }
    va_end(args);

    double action_1 = a*pow(x , 3) + b*pow(y , 2) - a*b;
    double action_2 = pow((a*pow(x , 3) + b*pow(y , 2) - a) , 2) + pi;
    double action_3 =  a*pow(x , 3) + b*pow(y , 2) - a*b;
    double result = abs(pow(sin(action_1) , 3) / (pow(sqrt(action_2) , 3))) + tan(action_3);
    cout << "Result: " << result << endl;

}

int main(){
    const int count = 4;
    const double x = 0.25;
    const double y = 1.31;
    const double a = 3.5;
    const double b = 0.9;
    result(count , x, y, a, b);
    
    return 0;
}