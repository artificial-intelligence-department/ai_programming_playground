#include <iostream>
using namespace std;
int main(){
    double s2, s1, v;
    //cout<< "Enter the first length, the second and your speed: \n";
    cin>> s2>> s1>> v;
    double Up = s1*2/v;
    double Down = s2/(v*2);
    if(s1>=0&&s2>=0&&v>=0){
        if (Up < Down) {
        cout<< "Up";
        }
        else if(Up > Down){
            cout<< "Down";
        }
        else if(Up == Down){
            cout<<"Never mind";
        }
    }
    else {
        exit(0);
    }
    return 0;
}

