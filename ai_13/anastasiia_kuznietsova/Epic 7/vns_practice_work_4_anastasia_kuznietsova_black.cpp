#include <iostream>
using namespace std;

int main()
{
    double price, cost;
    cout<<"Enter a price of the item for 1 kg: "; 
    cin>>price;
    cout<<"---------------------------\n";
    cout<<"|   Amount   |    Cost    |\n";
    cout<<"---------------------------\n";
    for(double mass=0.1; mass<=1.0; mass+=0.1)
    {
        cost = price * mass; // формула для обчислення вартості продукту
        cout<<"|     "<<mass<<"     |     "<<cost<<"     |\n";
        cout<<"---------------------------\n";
    }
    return 0;
}