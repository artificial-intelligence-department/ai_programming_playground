#include <iostream>
#include <cmath>

using namespace std;


double dil(int n1, int d1, int n2, int d2){
    double x;
    x=(double)(n1*d2)/(double)(n2*d1);
    cout << x;
    return x;
}

double dil(double n1, double n2){
    double x;
    x=n1/n2;
    cout << x;
    return x;
}

bool f;
double des1, des2;
int n1,d1,n2,d2;

int main(){
    cout << "Введіть 0 для звичайного дробу або 1 для десяткового дробу: " << endl;
    cin  >> f;
    if (f==0){
        cout << "Введіть чисельник 1 дробу: ";
        cin  >> n1;
        cout << "Введіть знаменник 1 дробу: ";
        cin  >> d1;
        cout << "Введіть чисельник 2 дробу: ";
        cin  >> n2;
        cout << "Введіть знаменник 2 дробу: ";
        cin  >> d2;
        if (d1==0 || d2==0 || n1==0){
            cout << "error";
        }
        else{
            dil(n1,d1,n2,d2);  
        }
    }
    else if (f==1){
        cout << "Введіть 1 дріб: ";
        cin  >> des1;
        cout << "Введіть 2 дріб: ";
        cin  >> des2;
        if (des2==0){
            cout << "error";
        }
        else{
            dil(des1,des2);  
        }
    }

}
