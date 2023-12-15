#include <cmath>
#include <iostream>
using namespace std;

float r;
float h;

float v;

//функція обчислення обєму
float vol(float r,float h){
    return M_PI*r*r*h;
}

int main(){
    //ввід
    cout << "Введіть початкові дані:"<< endl;
    cout << "Радіус підстави (см) >";
    cin>>r;
    cout << "Висот циліндра (см) >";
    cin>>h;
    //виклик функції
    v=vol(r,h);
    //вивід
    cout << "Об'їм "<< v<<" см.куб.";
}