#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int source = 15;
    int n;
    string input;
    cin >> n;
    cin >> input;

    for(int i = 0; i < n; i++){
        if(input[i] == 'k'){
            source = max(source - 1, 0);
        }
        else if(input[i] == 'p'){
            if(source != 0){
                source = 15;
            }
            else{
                source = 0;
            }
        }
        else if(input[i] == 'z'){
            if(source == 0){
                source = 15;
            }
            else if(source != 0){
                source = 0;
            }
        }
    
    }

    cout << source;

    return 0;
}