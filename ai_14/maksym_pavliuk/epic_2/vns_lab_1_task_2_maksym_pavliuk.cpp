#include<iostream>

using namespace std;

int main(){
    double m,n;
    
    cout << "\nInput M: ";
    cin >> m;
    cout << "\nInput N: ";
    cin >> n;

    double answer1;
    bool answer2, answer3;

    answer1 = --m-++n;
    cout << "\nAnswer 1 is: " << answer1 << endl;

    if(m*n<n++){
        answer2 = true;
    }else{
        answer2 = false;
    }
        
    cout << "\nAnswer 2 is: " << answer2 << endl;

    if(n-->m++){
        answer3 = true;
    }else{
        answer3 = false;
    }
    cout << "\nAnswer 3 is: " << answer3 << endl;

    return 0;
}