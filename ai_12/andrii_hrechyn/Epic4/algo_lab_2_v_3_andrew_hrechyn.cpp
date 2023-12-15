#include<iostream>
using namespace std;

int main(){
int N;
cin >> N;

int Battlefield[N];
for(int i=0; i < N; i++){
    cin >> Battlefield[i];
}

int right_position_of_drone = N;
int left_position_of_drone = 1;

do{
    if(left_position_of_drone == right_position_of_drone){
        cout << left_position_of_drone << " " << right_position_of_drone;
        cout << " Collision " << endl;
        break;
    }
    else if(left_position_of_drone > right_position_of_drone){
        cout << left_position_of_drone << " " << right_position_of_drone;
        cout << " Miss " << endl;
        break;
    }
    else if((left_position_of_drone + 1) == right_position_of_drone){
        cout << left_position_of_drone << " " << right_position_of_drone;
        cout << " Stopped " << endl;
        break;
    }
        
        left_position_of_drone += Battlefield[left_position_of_drone - 1];
        right_position_of_drone -= Battlefield[right_position_of_drone - 1];

}
while(true);
    return 0;
}