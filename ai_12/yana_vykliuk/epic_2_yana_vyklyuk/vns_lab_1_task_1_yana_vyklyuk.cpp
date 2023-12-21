#include <iostream>
#include <cmath>

using namespace std;

float a = 1000;
float b = 0.0001;

float Numeratorf = pow((a-b),3) - pow(a,3);
float Divisorf = pow (b,3) - 3 * a * pow(b,2) - 3 * pow(a,2) * b;

float Resultf = Numeratorf/Divisorf;

double ad = 1000;
double bd = 0.0001;

double Numeratord = pow((ad-bd),3) - pow(ad,3);
double Divisord = pow (bd,3) - 3 * ad * pow(bd,2) - 3 * pow(ad,2) * bd;

double Resultd = Numeratord/Divisord;

int main()
{
    cout << Resultf << endl;
    cout << Resultd << endl;

    return 0;
}
