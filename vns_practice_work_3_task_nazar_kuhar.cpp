#include <iostream>         
#include <cmath>            
using namespace std;        

double calculateTotalPrice(double copybookPrice, double pencilPrice, int copybookNumber, int pencilNumber)
{
    return copybookNumber * copybookPrice + pencilNumber * pencilPrice;         
}

double calculateVolumeOfCylinder(double r1, double r2, double h)        
{
    double r;           

    if(r1 > r2)         
    {
        r = M_PI * h * (pow(r1, 2) - pow(r2, 2));       
    }
    else        
    {
        r = M_PI * h * (pow(r2, 2) - pow(r1, 2));      
    }

    return r;       
}

int main()      
{
    double priceCopybook, pricePencil;      
    int copybookNumber, pencilNumber;       

    cout << endl;                                           
    cout << "|| The first part of program ||" << endl;      
    cout << "Enter the price of one copybook: ";
    cin >> priceCopybook;                                   
    cout << "Enter the number of copybooks: ";
    cin >> copybookNumber;

    cout << "Enter the price of one pencil: ";
    cin >> pricePencil;                              
    cout << "Enter the number of copybooks: ";
    cin >> pencilNumber;

    double totalPrice = calculateTotalPrice(priceCopybook, pricePencil, copybookNumber, pencilNumber); 

    cout << "The price of purchase is: " << totalPrice << endl;     
    cout << endl;

    double radius1, radius2, height;        

    cout << "|| The second part of program ||" << endl;
    cout << "Enter the length of first radius: ";
    cin >> radius1;
    cout << "Enter the length of second radius: ";
    cin >> radius2;
    cout << "Enter the length of height: ";
    cin >> height;

    double volume = calculateVolumeOfCylinder(radius1, radius2, height);        

    cout << "The volume of cylinder is: " << volume;

    return 0;        
}
