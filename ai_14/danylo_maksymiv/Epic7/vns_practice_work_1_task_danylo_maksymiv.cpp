#include <iostream>                 //інклудим модулі потоку вводу/виводу, математичний модуль і неймспейс стд щоб не писати std::
#include<cmath>         
using namespace std;

int main() 
{
    const double a =0.7,b=0.05,x=0.5;           //ініціалізую константні змінні з подвійною точністю відповідно до умови задачі
    double numerator_R = pow(x,3) * (x+1);      //розписую окремо знаменник та чисельник і  відʼємник
    double denominator_R = pow(b,2);
    double sin_R=pow(sin(x*(x+a)),2);
    double R =numerator_R/denominator_R -sin_R; //обчислюю значення виразу

    double applicaton1 = sqrt(x*b/a);           //розписую окремо доданки
    double applicaton2 = pow(cos(pow((x+b),3)),2); 
    double S=applicaton1+applicaton2;

    cout<< "R= "<< R<<endl<<"S= "<<S<<endl;                     //вивожу на екран результати
}
