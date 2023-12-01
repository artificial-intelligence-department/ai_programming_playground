#include <iostream>
#include <algorithm>
using namespace std;

struct mystr{
    int length, position, workers;
    double impact;
};

bool sortByImpact(mystr &a, mystr&b){
    return a.impact < b.impact;
}
    
int main() {
    
    int n, length, workers;
    cin >> n;
    
    mystr office[n];
    
    for (int i=0; i<n; i++){
        cin >> length;
        office[i].length = length;
        office[i].position = i+1;
    }
    
    for (int i=0; i<n; i++){
        cin >> workers;
        office[i].workers = workers;
    }
    
     for (int i=0; i<n; i++){
        double workers1 = office[i].workers;
        double length1 = office[i].length;
        office[i].impact = workers1/length1;
    }
    
    sort(&office[0], &office[n], sortByImpact);

    for (int i=n-1; i>=0; i--){
        cout << office[i].position << endl;
    }
    
    return 0;
}
