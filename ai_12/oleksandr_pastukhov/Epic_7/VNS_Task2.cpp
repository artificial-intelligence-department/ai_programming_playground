#include<iostream>
#include<cmath>

int main(){
    using namespace std;

    float x1 = -3;
    float x2 = 3;
    float h = 0.5;

    for(float i = x1;i <= x2;i += h){
        if(i != -1){
            double z = (cos(i)-1)/(i+1);
            cout << "x =" << i << "z = " << z << endl;
        }
        else{
            cout << "No value for x = -1";
        }
    }
    return 0;
}