#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    int x,y,r_amount = 0, u_amount = 0;
    cin >> x >> y;
    
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'R'){
            r_amount++;
        }
        else{
            u_amount++;
        }
    }

    if(x > r_amount || y > u_amount){
        cout << "NO";
    }
    else{
        cout << "YES";
    }

    return 0;
}