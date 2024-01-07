#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double R,H,Sb,Sc,S_circ;
    cout<<"\t\t\tCalculation of the total surface of the cylinder."<<endl;
    cout<<"Enter the initial data"<<endl;
    cout<<"Circle radius(cm) > ";
    cin>>R;
    cout<<"Height of the cylinder(cm) > ";
    cin>>H;
    R=abs(R);
    H=abs(H);
    Sb=2.0*M_PI*R*H;
    S_circ=2.0*M_PI*pow(R,2);
    Sc=Sb+S_circ;
    cout<<"The total surface area of ​​the cylinder: "<<Sc<<" sq.sm.";

    cout<<"________________________________________________________________________________"<<endl;
    double r,r1,r2;
    cout<<"\t\t\tResistance calculation."<<endl;
    cout<<"Enter the initial data"<<endl;
    cout<<"Resistance of first resistor(Om) > ";
    cin>>r1;
    cout<<"Resistance of second resistor(Om) > ";
    cin>>r2;
    r1=abs(r1);
    r2=abs(r2);
    r=1/(1/r1+1/r2);
    cout<<"The total resistance: "<<r<<" Om";
    return 0;
}