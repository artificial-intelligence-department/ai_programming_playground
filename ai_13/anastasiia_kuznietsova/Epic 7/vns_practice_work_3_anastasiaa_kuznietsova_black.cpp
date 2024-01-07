#include <iostream>
#include <cmath>
using namespace std;

void cubeVolume(double &side) //функція яка нічого не повертає. сторона позначається з посиланням, бо вона декларуєтьсяя в main 
{
    cout<<"Enter a side of a cube\n";
    cin>>side;

    double V=pow(side, 3);//формула для обчислення об'єму
    cout<<"Volume of the cube is "<<V<<" cubic cm";
}

void trapSquare (double &a, double &b, double &h)//функція для пошуку площі трапеції
{
    cout<<"Enter 2 sides of a trapeze:\n";
    cin>>a>>b;
    cout<<"Enter a hight of a trapeze:\n";
    cin>>h;

    double S=(a+b)/2*h;//формула для обчислення площі
    cout<<"Square of the trapeze is "<<S<<" cm";
}

void cylVolume (double &R, double &hc)//функція для пошуку об'єму циліндру
{
    cout<<"\nEnter a radius of a cylinder:\n";
    cin>>R;
    cout<<"Enter a hight of a cylinder:\n";
    cin>>hc;

    double V = M_PI*pow(R,2)*hc;//формула для пошуку об'єму. M_PI позначає число пі, яке знахоидть в бібліотеці cmath
    cout<<"Volume of the cylinder is "<<V<<" cubic cm";
}

int main()
{
    int number;
    cout<<"Choose a number from the menu: \n";
    cout<<"1. Volume of the cube\n2. Square of the trapeze\n3. Volume of the cylinder\n";
    cin>>number;

    switch (number)//оператор декількох варіантів
    {
        case 1://якщо ввели цифру 1
        double side;
        cubeVolume(side);
        break;

        case 2://якщо ввели цифру 2
        double a, b, h;
        trapSquare (a, b, h);
        break;

        case 3://якщо ввели цифру 3
        double R, hc;
        cylVolume (R, hc);
        break;
    }

    return 0;
}