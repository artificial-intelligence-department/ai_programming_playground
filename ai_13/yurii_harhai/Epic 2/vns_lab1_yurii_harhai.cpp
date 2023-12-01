#include <iostream>
#include <cmath>
using namespace std;
int main(){

    unsigned int a {1000};
    float b {0.0001};
    cout << "The result is: " <<(pow(a-b,3)-(pow(a,3)-3*pow(a,2)*b))/(pow(b,3)-(3*a*pow(b,2))) << endl;

    cout << "Enter m and n with space:";
    double m {0};
    double n {0};
    cin >> m >> n;
    cout << "1) --m-++n=" << --m-++n <<endl;
    if (m*n<n++){
        cout << "2) m*n<n++ is true" << endl;}
    else if(m*n>=n++){
        cout << "2) m*n<n++ is false" << endl;}
 
    if (n-->m++){
        cout << "3)n-->m++ is true" << endl;}
    else if (n--<=m++){
        cout << "3)n-->m++ is false" << endl;}
    

    return 0;    
}