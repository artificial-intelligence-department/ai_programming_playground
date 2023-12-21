#include <iostream>
#include <vector>

using namespace std;

int main(){
    int len,firstDrone,secondDrone;
    string ans;
    cin>>len;
    int array[len];
    
    for(int i =0;i<len;i++){
        cin>>array[i];
    }

    firstDrone = 1;
    secondDrone = len;
    for(int i =0;i<len;i++){
        if(firstDrone==secondDrone){
            ans = "Collision";
            break;
        }
        if((firstDrone+1)==secondDrone){
            ans = "Stopped";
            break;
        }
        if(firstDrone>secondDrone){
            ans = "Miss";
            break;
        }
        firstDrone += array[firstDrone-1];
        secondDrone -= array[secondDrone-1];
    }
    cout<<firstDrone<<" "<<secondDrone<<endl;
    cout<<ans;
}