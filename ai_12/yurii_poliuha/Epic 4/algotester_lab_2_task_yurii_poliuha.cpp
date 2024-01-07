#include <iostream>
using namespace std;

int limit(){
    bool review = false;
    int n;
    cin >> n;
    while(review == false){
        if(n > 1000 || n < 1) cin >> n;
        else review = true;
    }
    return n;
}

int LimitOfArray(){
    bool review = false;
    int n;
    cin >> n;
    while(review == false){
        if(n > 5 || n < 1) cin >> n;
        else review = true;
    }
    return n;
}

int main(){
    int N, left_d, right_d;
    N = limit();    
    
    int mas[N];
    for (int i = 0; i < N; i++){
        mas[i] = LimitOfArray();
    }
    cout << endl;

    left_d = 1;
    right_d = N;

    while (true) {  
        if(left_d == right_d){
            cout << left_d << " " << right_d << endl;
            cout << "Collision" << endl;
            break;
        }
        else if (right_d - left_d == 1){
            cout << left_d << " " << right_d << endl;
            cout << "Stopped" << endl;
            break;
        }
        else if (left_d > right_d){
            cout << left_d << " " << right_d << endl;
            cout << "Miss" << endl;
            break;
        }

        left_d += mas[left_d - 1];
        right_d -= mas[right_d - 1];
    }
    return 0;
}