#include <iostream>
#include <cmath>
#include <cstdarg>
using namespace std;
int kvadr(int num, ...);
float fdif(int n1, int d1, int n2, int d2);
float fdif(float n1, float n2);
int main(){
    int NumberOfKvadrats = kvadr(3,2,4,9);
    cout << "number of squeres is: " << NumberOfKvadrats << endl;
    NumberOfKvadrats = kvadr(7,1,2,9,5,16,8,49);
    cout << "number of squeres is: " << NumberOfKvadrats << endl;
    NumberOfKvadrats = kvadr(11,1,2,16,4,81,6,7,8,9,10,11);
    cout << "number of squeres is: " << NumberOfKvadrats << endl;

    int numerator1, domenator1, numerator2, domenator2;
    char symbol1, symbol2;
    float dif;
    cout << "Enter a fraction 1: ";
    cin >> numerator1 >> symbol1 >> domenator1;
    cout << "Enter a fraction 2: ";
    cin >> numerator2 >> symbol2 >> domenator2;
    if (symbol1 == '/' && symbol2 == '/'){
        dif = fdif(numerator1, domenator1, numerator2, domenator2);
    }
    else if (symbol1 == '.' && symbol2 == '.'){
        float num1 = numerator1 + domenator1 * 0.1;
        float num2 = numerator2 + domenator2 * 0.1;
        dif = fdif(num1, num2);
    }
    else{
        cout << "You entered wrong value!"; 
    }
    cout << dif;
    return 0;
}
float fdif(int n1, int d1, int n2, int d2){
    float dif = n1/(float)d1 - n2/(float)d2;
    return dif;
}
float fdif(float n1, float n2){
    float dif = n1 - n2;
    return dif;
}
int kvadr(int num, ...){
    int n = 0;
    va_list kvadrats;
    va_start(kvadrats, num);
    for (int i = 0; i < num; i++){
        int x = va_arg(kvadrats, int);
        int sqr = sqrt(x);
        if(sqr * sqr == x) n++;
    }
    va_end(kvadrats);
    return n;
}