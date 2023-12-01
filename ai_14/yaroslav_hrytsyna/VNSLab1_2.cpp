#include <iostream>
using namespace std;

double m;
double n;
double r1;
double r2;
double r3;

int main(){
std::cin >> m;
std::cin >> n;

r1=m+--n;
r2=(m++<++n);
r3=(n-->m);
std::cout << "1) " << r1 << endl;
std::cout << "2) " << r2 << endl;
std::cout << "3) " << r3 << endl;
}