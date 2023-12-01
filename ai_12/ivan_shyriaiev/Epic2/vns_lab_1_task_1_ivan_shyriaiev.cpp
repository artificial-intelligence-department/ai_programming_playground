#include<iostream>
#include<math.h>
using namespace std;

int main(){
float af = 1000, bf = 0.0001;
double ad = 1000, bd = 0.0001;
//float
    float c1 = (af - bf)*(af - bf)*(af - bf);
    float c2 = af*af*af - 3*af*af*bf;
    float c3 = bf*bf*bf - 3*af*bf*bf;
    float floatresult = (c1 - c2)/c3;
//double
    double x1 =  (ad - bd)*(ad - bd)*(ad - bd);
    double x2 = ad*ad*ad - 3*ad*ad*bd;
    double x3 = bd*bd*bd - 3*ad*bd*bd;
    double doubleresult = (x1 - x2)/x3;
    cout<<floatresult  << "  ||||||  "<< doubleresult<<"  ||||||  " ;
    return 0;
    
}