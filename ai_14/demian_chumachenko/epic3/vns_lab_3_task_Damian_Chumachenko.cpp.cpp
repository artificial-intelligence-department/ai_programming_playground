#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double Y, fract, SN, SE, eps = 0.0001;  
    int pos;

    for(float x = 0.1; x <= 1; x += 0.09){

        Y = (1 + pow(x, 2)) / 2 * atan(x) - x / 2;

        SN = 0;
        fract = 0;

        for(int n = 1; n <= 30; n++){
            fract = pow(-1, n + 1) * pow(x, 2 * n + 1) / (4 * pow(n, 2) - 1);
            SN += fract;
        }

        SE = 0;
        pos = 1;
        fract = 0;

        do{
            fract = pow(-1, pos + 1) * pow(x, 2 * pos + 1) / (4 * pow(pos, 2) - 1);
            SE += fract;
            pos++;
        } while(abs(fract) > eps);
        
        cout << "X = " << x << " SN = " << SN << " SE = " << SE << " Y = " << Y << endl;
    }
    return 0;
}