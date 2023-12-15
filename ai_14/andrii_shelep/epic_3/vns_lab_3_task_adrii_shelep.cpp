#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    const double PI = 3.141592653589793238;
    int n, N;
    double Y, A, A1, x = PI/5, a = PI/5, b = PI, Sn, Se;

    double det_x = (b-a)/10;

    for(int i = 1; i <= 10; i++){
        Sn = 0;
        for (n = 1; n <= 20; n++){
            A = pow(-1,n)*(cos(n*x)/pow(n,2));
            Sn += A;
        }
        Se = 0;
        N = 1;
        A1 = pow(-1, N) * (cos(N * x) / pow(N, 2));
        while (abs(A1) >= 0.0001){
            Se += A1;
            N++;
            A1 = pow(-1, N) * (cos(N * x) / pow(N, 2));
        }
        /*do {
            A1 = pow(-1, N) * (cos(N * x) / pow(N, 2));
            Se += A1;
            N++;
        } while (abs(A1) >= 0.0001);*/
        Y = (pow(x,2)-pow(PI,2)/3)/4;
        printf("X=%lf\t SN=%lf\t SE=%lf\t Y=%lf\t\n", x, Sn, Se, Y);
        x += det_x;
    }

    return 0;
}