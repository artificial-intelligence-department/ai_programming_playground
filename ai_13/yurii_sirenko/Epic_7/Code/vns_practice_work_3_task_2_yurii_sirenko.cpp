#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double pi = 3.14159; //Визначення константи Pi
    //Оголошення змінних, необхідних для задачі
    double volume,heigh,radius1,radius2;
    //Ввід даних
    cout<<"Enter the radius of the cylinder: \n";
    cin>>radius1;
    cout<<"Enter the hole radius: \n";
    cin>>radius2;
    cout<<"Enter the height of the cylinder: \n";
    cin>>heigh;
    //Обчислення та вивід даних з точністю до 5 знаків після коми
    cout<<"The volume of cylinder is: "<< fixed << setprecision(5) << pi*heigh*(pow(radius1,2)-pow(radius2,2));

    return 0;
}