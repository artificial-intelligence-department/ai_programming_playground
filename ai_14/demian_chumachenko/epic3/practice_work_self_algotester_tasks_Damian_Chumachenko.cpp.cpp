#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long n, a, sum = 0;
    vector<int> cookies;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        cookies.push_back(a);
    }

    for(int num : cookies){
        sum += num;
    }

    cout << sum - n;

    return 0;
}