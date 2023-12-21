#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int count;
    long sum = 0;
    cin >> count;
    vector<int> countp(count);

    for (int i = 0 ; i < count;i++ ){
        cin >> countp[i];
    }
    vector<int> countpupd(countp);

    for (int i = 0 ;i < count;i++){
        countpupd[i] = countp[i]-1; 
        sum += countpupd[i];
    }
    cout << sum;




    return 0;
}