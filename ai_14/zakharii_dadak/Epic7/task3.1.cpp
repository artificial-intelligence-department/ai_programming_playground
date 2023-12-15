#include <iostream>
#include <cmath>


using namespace std;

int main() {
    cout<<"Calculating the cylinder volume"<<endl;
    cout<<"Enter the starting data:"<<endl;
    cout<<"Radius of basis > "<<endl;
    int a;
    cin>>a;
    cout<<"Cylinder's high > "<<endl;
    int b;
    cin>>b;
    cout<<"Volume of a cylinder: "<< pow(a,2)*b*M_PI<<" cubic cm"<<endl;
    cout<<"To complete press <Enter>";
}
