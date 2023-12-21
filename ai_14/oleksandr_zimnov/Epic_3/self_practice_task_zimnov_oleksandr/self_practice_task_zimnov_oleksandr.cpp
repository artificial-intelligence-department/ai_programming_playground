#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N, drone1 = 0, drone2 = 0, temp1 = 0, temp2;
    cout << "Enter size of massive: ";
    cin >> N;
    while(N < 1 || N > 1000){
        cout << "Enter size of massive again (it's must be from 1 to 1000): ";
        cin >> N;
    }
    int* array = new int[N];
    cout << "Enter numbers for the massive: " << endl;
    for (int i = 0; i < N; i++) {
        cout << "Enter " << i+1 << " number: ";
        cin >> array[i];
        while(array[i] < 1 || array[i] > 5){
            cout << "Enter " << i+1 << " number again (it's must be from 1 to 5): ";
            cin >> array[i];
        }
    }
    temp2= N-1;
    for (int i = 0; i < N; i++) {
        if (temp1+1 < temp2) {
            temp1+= drone1;
            temp2-= drone2;
            if(temp1 > N-1){
                temp1=N-1;
            }
            if(temp2 < 0){
                temp2=0;
            }
            drone1 = array[temp1];
            drone2 = array[temp2];
        } else {
            break;
        }
    }
    if(temp1+1==temp2){
        cout << "Pos Drone1: " << temp1+1 << endl << "Pos Drone2: " << temp2+1<<endl;
        cout << "Stopped";
    }else{
        if(temp1==temp2){
        cout << "Pos Drone1: " << temp1+1 << endl << "Pos Drone2: " << temp2+1<<endl;
        cout << "Collision";
        }else{
        cout << "Pos Drone1: " << temp1+1 << endl << "Pos Drone2: " << temp2+1<<endl;
        cout << "Miss";
        }
    }
    return 0;
}
