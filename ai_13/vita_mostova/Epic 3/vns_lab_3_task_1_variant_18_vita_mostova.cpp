#include <iostream>
#include <cmath>

#define PI 3.1415
using namespace std;
int main(){

const double a=0.1;
const double b=0.8;
const double k=10;
const double step=(b-a)/k;
const double epsilon=0.0001;
double y,SN,SE,y1;


for(double x=a;x<=b;x+=step ){
     y= ((1.0/2) -(PI/4)*abs(sin(x))); //точне значення функції
// SN
 SN=0;    
for(int n=1;n<=50;n++){
double znam= ((4*(pow(n,2)))-1);
double chus= (cos(2*n*x));
y1=chus/znam;
 SN+=y1;
}
//  SE
   SE=0;
   int i=1; 
    
   do {
     double znam= ((4*(pow(i,2)))-1);
     double chus= (cos(2*i*x));
     y1=chus/znam;
     SE+=y1;
     i++;
    }while (abs(y1)>epsilon);
    
    
     

 cout << "X=" << x << " SN=" << SN << " SE=" << SE << " Y=" << y << "\n";
    }
return 0;
}


    