#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    //cout << "Enter the size of array: ";
    cin >> N;

    vector<int> cell(N);
    
    for (int a = 0; a<N; a++){
        //cout << "Enter the " << a+1 << " element of cells: ";
        cin >> cell[a];
    }

    int drone1 = 0, drone2 = N-1;
    if (drone1==drone2){
        cout << drone1+1 << endl;
        cout << drone2+1 << endl;
        cout << "Collision";
    }
    else if (drone2==drone1+1){
        cout << drone1+1 << endl;
        cout << drone2+1 << endl;
        cout << "Stopped";
        }
    else if (drone1 > drone2){
        cout << drone1+1 << endl;
        cout << drone2+1 << endl;
        cout << "Miss";
        }

    else {
        while (drone1 <= N-1 && drone2 >= 0){
        drone1+=cell[drone1];
        drone2-=cell[drone2];
        if (drone1==drone2){
            cout << drone1+1 << endl;
            cout << drone2+1 << endl;
            cout << "Collision";
            break;
        }
        else if (drone2==drone1+1){
            cout << drone1+1 << endl;
            cout << drone2+1 << endl;
            cout << "Stopped";
            break;
        }
        else if (drone1 > drone2){
            cout << drone1+1 << endl;
            cout << drone2+1 << endl;
            cout << "Miss";
            break;
        }
    }
    }
    return 0;
}
