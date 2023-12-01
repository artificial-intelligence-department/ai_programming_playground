#include<iostream>
#include<cmath>

using namespace std;

int main() 
{
 	int a = 100; 
	double result_d ,b =0.001;
	float result_f , bf=0.001;

	 result_d = (pow(a - b, 4) - (pow(a, 4) - 4 * pow(a, 3) * b + 6 * pow(a, 2) * pow(b, 2))) / (pow(b, 4) - 4 * a * pow(b, 3));
	 result_f = (pow(a - bf, 4) - (pow(a, 4) - 4 * pow(a, 3) * bf + 6 * pow(a, 2) * pow(bf, 2))) / (pow(bf, 4) - 4 * a * pow(bf, 3));
	
	cout<<"Result using double: "<<result_d<<endl;
	cout<<"Result using float: "<<result_f<<endl;
	return 0;
}
