#include <iostream>
int first(){
    long a;
    long int m;
    long n = 0;
    std::cin >> a;
    long int l = a;
    for (int i = 0; i < a ; i++){
        std::cin >> m;
        n += m;
        if (m <=0){
            --l;
        }
        }
    n -= l;
    std::cout<<n;
    return 0;
}
using namespace std;
int main (){
    long a;
    long int m;
    long int n = 0;
    cin >> a;
    for (int i = 0; i < a && 1<=a<=100000; i++){
        cin >> m;
        if(0<=m<=1000000000){
            if(m - 1 < 0){
            n += 0;
            } else{
            n += m - 1;
            }   
        } else{
            return 1;
        }
    }
    cout<<n<<endl;
    cout<<"\n";
    first();
    return 0;
}