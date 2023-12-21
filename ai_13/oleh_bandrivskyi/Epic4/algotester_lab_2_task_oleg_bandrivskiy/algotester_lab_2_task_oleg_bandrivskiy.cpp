#include <iostream>

using namespace std;


int main(){

    int size;
    int dronLeft = 0;
    bool position = true;


    cin >> size;
    int dronRight = size - 1;

    int arr[size];

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }   

    do
    {     
        if(dronLeft == dronRight){
            cout << dronLeft + 1 << " " <<  dronRight + 1 << endl;
            cout << "Collision";
            return 0;
        }else if(dronRight < dronLeft){
            cout << dronLeft + 1 << " " <<  dronRight + 1 << endl;
            cout << "Miss";
            return 0;
        }else if(dronRight == dronLeft + 1){
            cout << dronLeft + 1 << " " <<  dronRight + 1 << endl;
            cout << "Stopped";
            return 0;
        }else{
            dronLeft = dronLeft + arr[dronLeft];
            dronRight = dronRight - arr[dronRight];
        }


    } while(position);





    return 0;
}