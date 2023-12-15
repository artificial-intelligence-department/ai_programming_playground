
#include<iostream>
#include<cmath>
using namespace std;

double a = 0.1;
double b = 1;
int k = 10;
int n = 20;
double step = (b-a)/k;
double eps = 0.0001;

double factorial(int n)
{
    if (n == 1)
        return 1;
    else
    {
        return factorial(n - 1) * n;
    }
}

double teilorFormulaBySteps(int n,double x){
    double sum = 1;
    for(int i = 1;i < n+1;i++){
        sum += 2*x/factorial(i);
    }
    return sum;
}

double teilorFormulaByAcc(double eps,double x){
    double sum = 1;
    for(int i = 1;2*x/factorial(i) > eps;i++){
        sum += 2*x/factorial(i);
        x += step;
    }
    return sum;
}

double realSum(double x){
    double sum = 0;
    sum += pow(M_E,2*x);
    return sum;
}

int main(){
    for(double x = a;x <= b;x += step){
        cout << "x = " << x << " Acc = " << teilorFormulaByAcc(eps,x) << " Step = " << teilorFormulaBySteps(n,x) << " Real = " << realSum(x) << endl;
}
    return 1;
}

