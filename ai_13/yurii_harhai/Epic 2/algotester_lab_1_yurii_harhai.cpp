#include <iostream>
#include <string>
using namespace std;

int main(){
    
    long long int h[4] {0,0,0,0};
    long long int d[4] {0,0,0,0};
    long long int l {1000000000000};
    string name[4] {"first", "second", "third", "fourth"};
    bool Standing {true};
    bool Error {false};
    cout << boolalpha;   
    cout << "Enter your table legs length separated by space: \n";
    cin >> h[0] >> h[1] >> h[2] >> h[3];

    
    for (int i = 0; i < 4; i++){
        // cout << "How much do you want to saw off from the " << name[i] << " leg?\n";
        cin >> d[i];
            if( h[i] < d[i] ){
            Error = true;  
        }
            
        h[i]-=d[i];
            if (h[i]*2 <= h[0] || h[i]*2 <= h[1]  ||  h[i]*2 <= h[2]  ||  h[i]*2 <= h[3] ){
                Standing = false;
                
        }
    }
    if(Error == true)
        cout <<"ERROR";
    else if (Standing==false)
        cout << "NO";
    else 
        cout << "YES";
        
    return 0;
}