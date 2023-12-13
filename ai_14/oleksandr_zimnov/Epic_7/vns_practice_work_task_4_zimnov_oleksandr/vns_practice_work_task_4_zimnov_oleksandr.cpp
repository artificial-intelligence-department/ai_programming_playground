#include <iostream>

using namespace std;
int main() {
        int n, number, sum=0;
        cout << "Enter n: ";
        cin >> n;
        int i=0;
        do{ //8. в коді використаний do while цикл
            i++;
            cout<<"Enter "<<i<<" number: ";
            cin>>number;
            if(number%2!=0) //5. в коді використані умовні оператори та розгалуження
            break; //11. в коді використано оператори break і continue
            sum+=number;
            continue; 
        }
        while(i<n);
        cout<<"Your sum is: "<<sum;
}
