#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "How many numbers?";
    cin >> n;
    double ans = 0;
    for(int i=0;i<n;i++){
        double x;
        cin >> x;
        ans+=1/x;
    }
    ans = 1/ans;
    cout << "Average geometric: " << ans;
}