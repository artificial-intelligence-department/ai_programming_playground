#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    
    unsigned int n, length;
    cin >> n;
    
    vector<pair<int,int> > office;
    for (int i=0; i<n; i++){
        cin >> length;
        office.push_back({length, i+1});
    }

    sort(office.begin(), office.end());

    for (int i=0; i<n; i++){
        cout << office[i].second << endl;
    }
    return 0;
}