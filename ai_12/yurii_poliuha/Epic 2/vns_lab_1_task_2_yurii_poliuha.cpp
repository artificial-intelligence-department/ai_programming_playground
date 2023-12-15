#include<iostream>
using namespace std;

int main(){
    int n, m;
    cout<<"Enter number n and m pressing ENTER"<<endl;
    cin>>n>>m;
    cout<<"Value of number n "<<n<<endl;
    cout<<"Value of number m "<<m<<endl;

    //1. --m - ++n
    int num1 = --m - ++n;
    cout<<"Value of the '--m - ++n' function is "<<num1<<endl;
    ++m;
    --n;

    //2. m * n < n++
    int num2 = m * n < n++;
    if(num2 == 1){
        cout<<"Function (m * n < n++) is TRUE"<<endl;
    }
    else cout<<"Function (m * n < n++) is FALSE"<<endl;
    n--;

    //3. n-- > m++
    int num3 = n-- > m++;
    if(num3 == 1){
        cout<<"Function (n-- > m++) is TRUE"<<endl;
    }
    else cout<<"Function (n-- > m++) is FALSE"<<endl;

    return 0;
}