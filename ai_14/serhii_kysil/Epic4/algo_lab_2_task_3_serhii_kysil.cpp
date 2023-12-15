#include <iostream>
using namespace std;
int main(){
    int a;
    cin >> a;
    int* m = new int[a];
    for (int i = 0; i < a; i++){
        cin >> m[i];
    }
    int left = 1;
    int right = a;
    while(true){
        if (right == left){
            cout << left << " " << right << endl;
            cout << "Collision";
            break;
        }
        else if (right == left + 1){
            cout << left << " " << right << endl;
            cout << "Stopped";
            break;
        }
        else if (right < left){
            cout << left << " " << right << endl;
            cout << "Miss";
            break;
        }
        left = left + m[left - 1];
        right = right - m[right - 1];
        
    }
}