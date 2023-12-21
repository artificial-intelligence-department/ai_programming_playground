#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int a_d=1000;
    double b_d=0.0001;
    double d_d=3*a_d*a_d*b_d;
    int c_d=pow(a_d,3);
    double e_d=3*a_d*b_d*b_d;
    double f_d=pow(b_d,3);
    double h_d=pow((a_d-b_d),3);
    double result_d=(h_d-c_d)/(f_d-e_d-d_d);


    int a_f=1000;
    float b_f=0.0001;
    float d_f=3*a_f*a_f*b_f;
    int c_f=pow(a_f,3);
    float e_f=3*a_f*b_f*b_f;
    float f_f=pow(b_f,3);
    float h_f=pow((a_f-b_f),3);
    float result_f=(h_f-c_f)/(f_f-e_f-d_f);

    cout<<result_d<<endl;
    cout<<result_f;

}