#include <iostream>       //дозволяє використовувати виведення(cout) і введеня(cin)
#include <cmath>          //містить функції для математичних операцій

using namespace std;

void sum(double x, double y){    //дозволяє більш зручно користуватися програмою та читати код 
    double z;   // задаю змінну типу double  
    z=sin(pow(x, 3))+pow(cos(y), 2); 
    cout<<"z = "<<z<<endl; //через cout виводжу змінну z
}

int main(){
    double x=1.2, y=-0.8; //задаю змінні типу double, та задаю їм значення 
    double s=1;
    for(int i=1; i<=4; i++){ //використовую цикл for для обчислення послідовності
        s+=pow(x,i)/i;
    }
    cout<<"s = "<<s<<endl; //через cout виводжу даний результат 

    sum(x, y); //переносимо функцію sum до головної функції
    
    return 0;

}