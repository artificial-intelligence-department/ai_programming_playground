#include<iostream>
#include<cmath>
using namespace std;

float convert(int a, int b){
    float c = static_cast<float>(a)/b;
    return c;
}
void convert(float a){
    float fractional_part;
    fractional_part = a - static_cast<int>(fractional_part);

    int amount=0;
    while (fractional_part > 0.0) {
        fractional_part *= 10;
        fractional_part = fractional_part - static_cast<int>(fractional_part);
        amount++;
    }
    cout << "\n" << a*pow(10, amount) << "/" << pow(10, amount);
}

int main(){
    int a,b,choice;
    float c;
    cout << "what way would you like to convert(1-Dec->frac; 2-Frac->dec)";
    cin >> choice;
    if(choice==1){
        cout << "\nInput the dec fraction: ";
        cin >> c;
        convert(c);
    }else if(choice==2){
        cout << "\nInput the the numerator and the denominator: ";
        cin >> a;
        cin >> b;
        cout << "\n" << convert(a,b);
    }else{
        cout << "\nInvalid choice";
    }
    
    return 0;
}
