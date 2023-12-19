#include<iostream>
#include<cmath>
using std::cout, std::cin, std::endl;
void WithFloat(){
    float a = 100,b = 0.001;
    float numenator = pow((a+b),4)-(pow(a,4)+(4*pow(a,3)*b)+(6*pow(a,2)*pow(b,2)));
    float denominator = (4*a*pow(b,3))+pow(b,4);
    float result = numenator/denominator;
    cout << "The result (using type float) is: " << result << endl;
}

void WithDouble(){
    double a = 100,b = 0.001;
    double numenator = pow((a+b),4)-(pow(a,4)+(4*pow(a,3)*b)+(6*pow(a,2)*pow(b,2)));
    double denominator = (4*a*pow(b,3))+pow(b,4);
    double result = numenator/denominator;
    cout << "The result (using type double) is: " << result << endl;
}

int main(){
    WithDouble();
    WithFloat();
    return 0;
}