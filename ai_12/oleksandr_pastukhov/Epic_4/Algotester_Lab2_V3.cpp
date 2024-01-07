#include<iostream>
#include<vector>

int main(){
    using namespace std;

    int n;
//    cout << "Enter size of your array: " << endl;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int FirstDronePos = 1;
    int SecondDronePos = n;

    while(true){

        if(FirstDronePos == SecondDronePos){
            cout << FirstDronePos << " " << SecondDronePos << endl;
            cout << "Collision" << endl;
            break;
        }  

        else if(FirstDronePos > SecondDronePos){
            cout << FirstDronePos << " " << SecondDronePos << endl;
            cout << "Miss" << endl;
            break;
        }

        else if(FirstDronePos + 1 == SecondDronePos){
            cout << FirstDronePos << " " << SecondDronePos << endl;
            cout << "Stopped" << endl;
            break;
        }

        FirstDronePos += arr[FirstDronePos-1];
        SecondDronePos -= arr[SecondDronePos-1];

    }
    return 0;
}
/*#include<iostream>
#include<vector>
int main(){
    using namespace std;
    int n;
    cout << "Enter size of your array: " << endl;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int FirstDronePos = 1;
    int SecondDronePos = n;
    while(true){
        int NewFirstDronePos;
        bool FirstIsStopped = false;
        (FirstDronePos + arr[FirstDronePos-1] < n) ?  NewFirstDronePos = FirstDronePos + arr[FirstDronePos-1] : FirstIsStopped = true;
            
        int NewSecondDronePos;
        bool SecondIsStopped = false;
        (SecondDronePos - arr[SecondDronePos-1] > 1) ? NewSecondDronePos = SecondDronePos - arr[SecondDronePos-1] : SecondIsStopped = true;
        
        if(NewFirstDronePos == NewSecondDronePos){
            cout << NewFirstDronePos << " " << NewSecondDronePos << endl;
            cout << "Collision" << endl;
            break;
        }  
        else if(NewFirstDronePos > NewSecondDronePos){
            cout << NewFirstDronePos << " " << NewSecondDronePos << endl;
            cout << "Miss" << endl;
            break;
        }
        else if(NewFirstDronePos + 1 == NewSecondDronePos & FirstIsStopped & SecondIsStopped){
            cout << NewFirstDronePos << " " << NewSecondDronePos << endl;
            cout << "Stopped" << endl;
        }
    }
    return 0;
}*/