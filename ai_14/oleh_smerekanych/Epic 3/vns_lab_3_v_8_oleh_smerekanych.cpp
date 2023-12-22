#include <iostream>
#include <cmath> 
using namespace std;

int main () {
    double x, a = 0.1, b = 0.81, k = 10, epsi = 0.0001, sn, se, y;
    int N = 10;

    for(double x = a; x <= b; x += (b-a)/k)
    {
        sn = 0;
        for(int n = 1; n <= N; n++)
        {
            sn += pow(x,n)*sin(N*(M_PI/4));
                }
        for(int n = 1; n <= N; n++){
            se += pow(x,n)*sin(N*(M_PI/4));
            if(se > epsi ){
                continue;
            }
            else{
                break;
            }
        }
        y = (x*sin(M_PI/4))/(1-2*x*cos(M_PI/4)+pow(x,2));
    
        cout << "X = " << x  << "\tSN = " << sn  << "\tSE = " << se << "\tY= " << y << endl;
    }
    return 0;
}