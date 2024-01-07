#include<iostream>
#include<cmath>
using namespace std;
#define pi 3.14159265359//для зручності визначаємо число пі

struct cylinder{ //структура з двома полями типу double
    double radius;
    double height;
};
double resistance( double I, int count = 3){//рекурсивна функція для знаходження опору якщо наявні дані - напруга та сила струму
    if(count==0){
        return 0;
    }
    double U;
    cout<<"Enter voltage on this resistor";
    cin>> U;
    double R = U/I;//знаходимо опір
    return R + resistance(I,count-1);//рекурсивний визов функції
}
double resistance(int count = 3){//рекурсивна функція для знаходження опору кола якщо наявна інформація - опори резисторів
    if(count==0){
        return 0;
    }
    double R;
    cin>>R;
    return R + resistance(count-1);//рекурсинвий визов 
}
int main(){
    cylinder cyl;//структура з параметрами циліндру 

    cout<<"Enter the data:\nRadius of the foundation (cm)>  ";
    cin>>cyl.radius;
    cout<<"Height (cm)> ";
    cin>>cyl.height;
    cout<<"Volume of the cylinder "<<pi*pow(cyl.radius,2)*cyl.height<<" cm^3\n\n";//знаходимо об'єм
    
    
    cout<<"Calculate the resistance of electrical circuit\n";

    char ch;
    cout<<"If you just want to find the sum of resistances enter Y, otherwise - enter N\n";
    cin>> ch;
    if(ch=='Y'){//розгалуження для того щоб з'ясувати яку варіацію функції викликати
        double res = resistance();//якщо тільки опори
        cout<<res;
    } else{
        cout<<"enter power of the circuit\n";//інший випадок
        double power;
        cin>> power; 
        double res = resistance(power);
        cout<<res;
    }
    
    return 0;
    
    
}