#include<iostream>

using namespace std;

int main(){
    int a[5];
    int wincheck = 0;
    bool ERROR_check;

    for(int i=0; i<5; i++){
        printf("\nInput a[%i]: ", i);
        cin >> a[i];
        if (a[i] <= 0){
            ERROR_check = 1;
            break;
        }
    }
    
    if(ERROR_check == 0){
        for(int i=1; i<5; i++){
            if (a[i] < a[i-1]){
                printf("\nCube %i placed successfully", i);
                wincheck++;
            } else{
                printf("\nCube %i was bigger then the previous one, GAME OVER \n", i);
                break;
            }
        }
        if (wincheck == 4){
            cout << "\n\nYou won !!! \n" << endl; 
        }
    } else {
        cout << "Error(your input is an inapropriate number for a side of a cube)" << endl;
    }
    
    return 0;
}