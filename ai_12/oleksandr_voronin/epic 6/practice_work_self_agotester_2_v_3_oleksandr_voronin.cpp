#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> Drones;
    int N;
    cin >> N;
    
    for(int i = 0;i<N;i++){
        int add;
        cin >> add;
        Drones.push_back(add);
    }

    int drone1 = 1;
    int drone2 = N;
    for(int j =0;j< N;j++){
       if (drone1 == drone2){
            cout << drone1 << ' ' << drone2 << endl;
            cout << "Collision";
            return 0;
        }
       else if (drone1 == drone2 - 1){
            cout << drone1 << ' ' << drone2 << endl;
            cout << "Stopped";
            return 0;
        } 
         else if (drone1 > drone2){
            cout << drone1 << ' ' << drone2 << endl;
            cout << "Miss";
            return 0;
        }
        drone1 += Drones[drone1 - 1];
        drone2 -= Drones[drone2 - 1];
    }
    

}