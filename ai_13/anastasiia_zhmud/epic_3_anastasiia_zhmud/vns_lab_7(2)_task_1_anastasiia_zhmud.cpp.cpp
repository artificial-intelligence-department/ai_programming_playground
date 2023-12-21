#include <iostream>
#include<cmath>
using namespace std;

     double area(int x1, int y1, int x2, int y2, int x3, int y3) {
        return abs(0.5*((x1*y2+x2*y3+x3*y1)-(y1*x2+y2*x3+y3*x1)));
    }
    bool belong(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3) {
     double total_area = area(x1, y1, x2, y2, x3, y3);
     double area1 = area(x, y, x2, y2, x3, y3);
     double area2 = area(x1, y1, x, y, x3, y3);
     double area3 = area(x1, y1, x2, y2, x, y);
    if(total_area==area1+area2+area3){
        return true; 
    } else{
        return false;
    }
}
int main() {
    int x1, y1;
    cin>>x1>>y1;
    int x2, y2;
    cin>>x2>>y2;
    int x3, y3;
    cin>>x3>>y3;
    int x, y;
    cin>>x>>y;
    if (belong(x, y, x1, y1, x2, y2, x3, y3)==1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
    return 0;
}