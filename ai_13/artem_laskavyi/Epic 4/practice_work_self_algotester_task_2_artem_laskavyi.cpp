#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){ 

    int N, num;
    vector<int> arr, del;
    vector<int>::iterator it;

    cin >> N;

    for (int i=0; i<N; i++){ 
    cin >> num;
    arr.push_back(num);
    }

    for (int i=0; i<3; i++){ 
    cin >> num;
    del.push_back(num);
    }
    
    for(int i = 0; i < 3; i++ ){
        auto it = find(arr.begin(), arr.end(), del[i]);
            if (it != arr.end()){
                arr.erase(it);     
            }
    }

    int new_size = (arr.size() != 0) ? arr.size()-1 : 0;
    int arrnew[new_size]; 

    for (int i=0; i < new_size; i++){ 
    arrnew[i] = arr[i]+ arr[i+1];
    }

    cout << new_size << endl;

    for (int i=0; i < new_size; i++){ 
    cout << arrnew[i] << " ";
    }
    cout << endl;

return 0;
}