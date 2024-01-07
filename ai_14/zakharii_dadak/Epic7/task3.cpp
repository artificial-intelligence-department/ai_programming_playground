#include <iostream>
#include <cmath>


using namespace std;

int main() {
    cout<<"Calculating the cube's volume"<<endl;
    cout<<"Enter the lenght of edge (cm) and press <Enter>"<<endl<<">";
    int a;
    cin>>a;
    cout<<"Volume of a cube: "<< pow(a,3)<<" cubic cm";
}
