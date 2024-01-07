#include <iostream>
#include <cmath>
#include <cstdarg>
using namespace std;


double AngleOfTriangle(double a, double b, double c){    
    double Angle = acos((pow(b, 2) + pow(c, 2) - pow (a, 2)) / (2 * b * c)) * (180 / M_PI);
    return Angle;
}

void AngleOfPolygon (double sides, ...){
    va_list args;
    va_start(args, sides);
    double AnglesSum;
    int count = 0;
    
    for(int i = 0; i < sides; i++){
        count++;
    }

    AnglesSum = 180 * (count - 2); //визначення суми кутів n-кутника
    cout << "The sum of angles is " << AnglesSum << endl;

    cout << endl;
    va_end(args);
}

int main(){
    double a, b, c;
    bool review = false;
    cout << "Enter your values to each side" << endl;
    cin >> a >> b >> c;
    while(review == false){
        if(a + b < c || a + c < b || b + c < a){
            cout << "ERROR. Try again" << endl;
            cin >> a >> b >> c;
        }
        else review = true;
    }
    double angle = AngleOfTriangle(a, b, c);
    cout << "Angle of triangle is " << angle << endl;
    cout << endl;

    AngleOfPolygon(9, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    AngleOfPolygon(11, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);

    return 0;
}