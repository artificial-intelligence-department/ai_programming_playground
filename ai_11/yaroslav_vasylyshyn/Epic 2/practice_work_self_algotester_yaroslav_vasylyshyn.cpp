#include <iostream>
using namespace std;
int main() {
    //Задача з алготестера бісеня
    int n,m,b;
    cin>>n>>m;
    b=n*m;
    if (b % 2 > 0){
        cout << "Imp";
    }else{
        cout << "Dragon";
    }
    return 0;
}
