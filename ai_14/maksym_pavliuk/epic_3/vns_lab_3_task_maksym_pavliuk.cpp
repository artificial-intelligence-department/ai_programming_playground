#include <iostream>
#include <cmath>

using namespace std;

int main (){
    const float a=0.2,b=1, epsilon = 0.0001;
    for (float x = a; x <= b; x = x + (b-a)/10){
        double SN = 0, SE = 0, R = 1;
        for(int n=0; n < 10; n++){
            SN += (1/(2*n+1))*pow((x-1)/(x+1), (2*n+1));
        }
        for(int n=0; R>epsilon; n++){
            R = (1/(2*n+1))*pow((x-1)/(x+1), (2*n+1));
            SE += (1/(2*n+1))*pow((x-1)/(x+1), (2*n+1));
        }
        double Y = 0.5*log(x);

        cout << "X = " << x << " | " << "SN = " << SN << " | " << "SE = " << SE << " | " << "Y = " << Y << endl;

    }

    return 0;
}
