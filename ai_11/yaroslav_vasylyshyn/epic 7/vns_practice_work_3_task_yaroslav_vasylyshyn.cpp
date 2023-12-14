#include <iostream>
#include <cmath>

using namespace std;

int main(){
    //variant 16
    double vnesok, period, stavka, doxid, zahalne, h , pi = 3.14, r1, r2, V;
    cout<<"Величина внеску (грн.): "; 
    cin>>vnesok;
    cout<<"Термін внеску (днів): "; 
    cin>>period;
    cout<<"Процентна ставка (річних в %): "; 
    cin>>stavka;
    doxid = vnesok * ((period/365)*(stavka/100));
    zahalne = vnesok + doxid;
    cout<<'\n'<<"Дохід: "<<doxid; 
    cout<<'\n'<<"Сума, після закінчення терміну внеску: "<<zahalne; 
    cout<<"\n\n";
    //r2<r1
    cout<<"радіус циліндра: "; 
    cin>>r1;
    cout<<"радіус отвору: "; 
    cin>>r2;
    cout<<"висота циліндра: "; 
    cin>>h;
    V = pi*h*(r1*r1-r2*r2);
    cout<<"Об'єм порожнистого циліндра: "<<V; 
    return 0;
}