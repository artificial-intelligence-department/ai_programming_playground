//епік 2 лаба 1(1)
#include <iostream>
#include <cmath>

using namespace std;
int main (){
double a=1000;
double b=0.0001;
double action1= pow(a+b, 3);
double action2=pow(a,3);
double action3=3*a*pow(b,2);
double action4=pow(b,3);
double action5=3*pow(a,2)*b;
double result=(action1-action2)/(action3+action4+action5);

cout <<result<< endl;


float a_f=1000;
float b_f=0.0001;
float action1_f= pow(a_f+b_f, 3);
float action2_f=pow(a_f,3);
float action3_f=3*a_f*pow(b_f,2);
float action4_f=pow(b_f,3);
float action5_f=3*pow(a_f,2)*b_f;
float result_f=(action1_f-action2_f)/(action3_f+action4_f+action5_f);

cout <<result_f<< endl;
return 0;
}

//float result_f=((pow(a_f+b_f, 3))-(pow(a_f,3)))/((3*a_f*pow(b_f,2))+(pow(b_f,3))+(3*pow(a_f,2)*b_f));

