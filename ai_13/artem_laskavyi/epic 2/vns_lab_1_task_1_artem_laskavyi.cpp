#include <iostream>
#include <cmath>
using namespace std;

int main()
{
 double a = 100.0;
 double b = 0.0001;
 
 double res1 = pow(a+b, 4);

 double res2 = (pow(a, 4)+4*pow(a, 3)*b);

 double res3 = (6*pow(a, 2)*pow(b, 2));

 double res4 = 4*a*pow(b, 3);

 double res5 = pow(b, 4);

 double final = (res1 - res2)/(res3 + res4+ res5);
 cout << final << endl;
 cout << "--------------------" << endl;
 
 float a_f = 100;
 float b_f = 0.0001;

 float res1_f = pow(a_f+b_f, 4);

 float res2_f = (pow(a_f, 4)+4*pow(a_f, 3)*b_f);

 float res3_f = (6*pow(a_f, 2)*pow(b_f, 2));

 float res4_f = 4*a_f*pow(b_f, 3);
 
 float res5_f = pow(b_f, 4);

 float final_f = (res1_f - res2_f)/(res3_f +res4_f+res5_f);
 cout << final_f << endl;
 return 0;
}