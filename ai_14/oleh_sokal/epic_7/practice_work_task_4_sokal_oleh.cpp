#include <iostream>
#include <iomanip>  
using namespace std;


int main(){
    double result = 0;
    int n,i=0;
    double number;
    cin >> n;
    do{
        cin >> number;
        result += number;
        i++;
    }while(i<n);
    result /= n;
   
    cout << fixed << setprecision(9) << result;
    return 0;
}
