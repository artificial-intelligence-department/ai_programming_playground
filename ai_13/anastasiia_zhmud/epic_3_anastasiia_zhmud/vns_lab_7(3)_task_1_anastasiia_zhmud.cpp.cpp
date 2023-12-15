#include <iostream>
#include <cmath>
using namespace std;

bool point_belong(int k, int x, int y,  int x1, int y1, int x2, int y2, int x3, int y3,...){
    int* p=&y;
    int* p1=&y;
    int s=0, s1=0;
    double area=0.0, area1=0.0;
    int x0, y0, x01,y01, k1=k;
    for(; k!=0; --k){
        if(k==1){
            x0=*(++p);
            y0=*(2+p1);
            y01=*(1+p);
            x01=*(++p1);
        }
        else{
            x0=*(++p);
            y0=*(3+p);
            y01=*(1+p);
            x01=*(2+p);
        }
        s+=x0*y0;
        s1+=y01*x01;
        p++;
    }
    p=&y;
    area=0.5*abs(s-s1);
    x0 =0, y0=0, y01=0, x01=0;
    for(; k1!=0; --k1){
        if(k1==1){
            x0=*(p1);
            y0=*(++p1);
            x01=*(++p);
            y01=*(1+p);
        } 
        else{
        x0=*(p1);
        y0=*(++p1);
        x01=*(1+p1);
        y01=*(2+p1);}
        p1++;
        area1+=0.5*abs((x*y0+x0*y01+x01*y)-(y*x0+y0*x01+y01*x));
    }
    return area==area1;
}
int main(){
    if(point_belong(6, 2,0,-2,-2,1,-3,3,0,1,3,4,2,1,1)){
        cout<<"Point (2;0) belong to this polygon";
    }
    else{
        cout<<"Point (2;0) don't belong to this polygon";
    }
}