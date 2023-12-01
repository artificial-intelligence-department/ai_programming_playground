#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a = 1.0;
    double b = 2.0;
    int n = 15;
    double elp = 0.0001;
    
    for(double x = a; x <= b + elp; x += (b - a) / 10){
        double SRn = 1.0 + x;
        double SRelp = 1.0 + x;
        
        for(int i = 2; i <= n; ++i){
            long long factorial = 1;
            //double factorial = 1.0;
            for(int j = 1; j <= i; ++j){
                factorial *= j;
            }
            SRn += pow(x, i) / factorial;
        }
        double xe = x;
        //int k = 2;
        for(int k = 2; xe > elp; k++){
            xe *= x / k;
            SRelp += xe;
        }
        

        double y = exp(x);
        cout<<"X= "<< x <<" SN = "<< SRn <<" SE = "<< SRelp << " Y = "<< y << endl;
       
        
    }
    
    return 0;
}
