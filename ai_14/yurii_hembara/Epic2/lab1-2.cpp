#include<iostream>

using namespace std;

int main(){
    double m,n;
    
    cout << "\nEnter number M: ";
    cin >> m;
    cout << "\nEnter number N: ";
    cin >> n;

    double fir_ans;
    bool sec_ans, thi_ans;

    fir_ans = --m-++n;
    cout << "\nFirst answer(--m-++n): " << fir_ans << endl;

    if(m*n<n++){
        sec_ans = true;
    }else{
        sec_ans = false;
    }
        
    cout << "\nSecond answer(m*n<n++): " << sec_ans << endl;

    if(n-->m++){
        thi_ans = true;
    }else{
        thi_ans = false;
    }
    cout << "\nThird answer(n-->m++): " << thi_ans << endl;

    return 0;
}
