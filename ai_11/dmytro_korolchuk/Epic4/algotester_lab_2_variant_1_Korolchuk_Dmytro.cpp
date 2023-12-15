#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int max, min;
    int len;
    cin>>len;
    vector <int> array(len), MinimalCase(len);
    for(int i =0;i<len;i++){
        cin>>array[i];
    }
    for(int i =0;i<len;i++){
        vector <int> tempArray = array;
        tempArray.erase(tempArray.begin()+i);
        min = *min_element(tempArray.begin(), tempArray.end()); 
        max = *max_element(tempArray.begin(), tempArray.end());
        MinimalCase[i] = max-min;
    }
    cout<<*min_element(MinimalCase.begin(),MinimalCase.end());
    return 0;
}