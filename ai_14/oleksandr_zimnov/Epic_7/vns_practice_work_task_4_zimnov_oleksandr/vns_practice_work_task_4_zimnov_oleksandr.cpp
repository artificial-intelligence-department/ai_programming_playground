#include <iostream>

using namespace std;
int main() {
        int n, number, sum=0;
        cout << "Enter n: ";
        cin >> n;
        for(int i=0; i<n; i++){
            cout<<"Enter "<<i+1<<" number: ";
            cin>>number;
            if(number%2==0) //the if function is used for comparison, only if done correctly the execution of the part of the code is executed. == means comparison. % means division without a remainder
            sum+=number;
        }
        cout<<"Your sum is: "<<sum;
}
