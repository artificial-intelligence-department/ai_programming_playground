#include <iostream>

using namespace std;

double Mul(double a, double b){
    return a * b;
}
void Mul(int x1, int x2, int y1, int y2, int& r1, int& r2){
    r1 = (x1*x2-y1*y2);
    r2 = (x1*y2+x2*y1);
}


int main(){
    double a, b;
    int x1, x2, y1, y2, r1, r2, choise;
    cout<<"1.Дійсне.\n";
    cout<<"2.Комплексне.\n";

    cin>>choise;

    switch(choise){
        case 1:

            cout<<"a = ";
            cin>>a;
            cout<<"b = ";
            cin>>b;
            cout << Mul(a, b)<<endl;
            break;
        case 2:
            cout<<"x1 = ";
            cin>>x1;
            cout<<"x2 = ";
            cin>>x2;
            cout<<"y1 = ";
            cin>>y1;
            cout<<"y2 = ";
            cin>>y2;
            Mul(x1,x2,y1,y2,r1,r2);
            cout << r1 << " + i" << r2;
            break;


    }

    
}