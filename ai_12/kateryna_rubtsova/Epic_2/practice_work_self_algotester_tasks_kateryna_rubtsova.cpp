#include <iostream>

using namespace std;

int main()
{
    long int n;
    long long int u, sum = 0;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        sum+= arr[i];
    }
    u = sum - n;
    cout << u;

    return 0;
}
