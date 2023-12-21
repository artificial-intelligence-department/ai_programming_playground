#include <iostream>
#include <vector>
using namespace std;

int main(){

    int N, num; 

    vector<int> a;
    cin >> N;   
    for (int i=0; i < N; i++){ 
        cin >> num;
        a.push_back(num);
    }
 
    int drone1 = 0;
    int drone2 = a.size()-1;
    bool flying = true;

    while(flying == true){
        if(drone1 == drone2){
            flying = false;
            cout << drone1 + 1 << " " << drone2 + 1 << endl;
            cout << "Collision" << endl;
            break;
        }else if(drone1 == drone2 - 1){
            flying = false;
            cout << drone1 + 1 << " " << drone2 + 1 << endl;
            cout << "Stopped" << endl;
            break;
        }else if (drone1 > drone2){
            flying = false;
            cout << drone1 + 1 << " " << drone2 + 1 << endl;
            cout << "Miss" << endl;
            break;
        }
        drone1 += a[drone1];
        drone2 -= a[drone2];

    }

    return 0;
}