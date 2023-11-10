#include <iostream>
#include <math.h>
using namespace std;

int main(){
    //Task 1
    // float a=100,b=0.001;
    // float q=pow((a-b), 4);
    // float w=pow(a, 4);
    // float e=(4*pow(a, 3)*b);
    // float r=(6*pow(a, 2)*pow(b, 2));
    // float t=(4*a*pow(b, 3));
    // float y=(pow(b, 4));
    // float res=((q-(w-e))/(r-t+y));
    // printf("%.8f", res);
    // cout<<'\n';
    double a=100,b=0.001;
    double q=pow((a-b), 4);
    double w=pow(a, 4);
    double e=(4*pow(a, 3)*b);
    double r=(6*pow(a, 2)*pow(b, 2));
    double t=(4*a*pow(b, 3));
    double y=(pow(b, 4));
    double res=((q-(w-e))/(r-t+y));
    printf("%.8lf", res);
    cout<<'\n';

    //Task 2
    int n,m=0;
    cin>>n>>m;
    bool c = m-->m;
    cout<<"n++*m = "<<(n++*m)<<" (= n*m, n+=1)"<<'\n';
    cout<<(n++<m)<<" depends on n,m True(if n+1<m) False if n+1>=m"<<'\n';
    cout<<(c)<<" always true"<<'\n';
    return 0;
}