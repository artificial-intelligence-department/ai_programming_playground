#include <iostream>
#include <cmath>

float findNaturalLog(float x){
    return logf(x);
}
double findNaturalLog(double x){
    return log(x);
}
long double findNaturalLog(long double x){
    return logl(x);
}

float findCommonlLog(float x){
    return log10f(x);
}
double findCommonLog(double x){
    return log10(x);
}
long double findCommonLog(long double x){
    return log10l(x);
}

int main(){
    auto a = findNaturalLog(10000.0), b = findCommonLog(10000.0);

    std::cout << "The natural logarithm of 10000 is: " << a << ". The common logarithm of 10000 is: " << b << ".";
}