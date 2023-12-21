#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortDescending(const int &a, const int &b){
    return (a > b);
}

int main(){ 

    int N, num, remainder;
    vector<int> general, rem0, rem1, rem2, result;

    cin >> N;

    for (int i=0; i<N; i++){ 
        cin >> num;
        general.push_back(num);
    }

    sort(general.begin(), general.end());
    auto last = std::unique(general.begin(), general.end());
    general.erase(last, general.end());

    for (int i=0; i < general.size(); i++){ 
        remainder = general[i] % 3;
        if(remainder == 0){
            rem0.push_back(general[i]);
        }else if(remainder == 1){
            rem1.push_back(general[i]);
        }else{
            rem2.push_back(general[i]);
        }
    }

    sort(rem0.begin(), rem0.end());
    sort(rem1.begin(), rem1.end(), sortDescending);
    sort(rem2.begin(), rem2.end());
    
    result.reserve( rem0.size() + rem1.size() + rem2.size()); // preallocate memory
    result.insert( result.end(), rem0.begin(), rem0.end() );
    result.insert( result.end(), rem1.begin(), rem1.end() );
    result.insert( result.end(), rem2.begin(), rem2.end() );

    cout << result.size() << endl;

    for (auto i : result){ 
        cout << i << ' '; 
    }

    cout << endl;
    
return 0;
}