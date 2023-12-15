#include <iostream>
#include <vector>

using namespace std;

int MaxSum(vector<vector<int>> array, int rows, int cols){
    int maxsum = 0;
    for(int l = 0; l < cols - 1; l++){
        int sum = 0;
        for(int j = 0; j < rows - l - 1; j++){
            sum += array[j][l];
        }
        if(sum >= maxsum){
            maxsum = sum;
        }
    }
    return maxsum;
}

int main(){
    vector<vector<int>> array = {
        {1, 2, 3, 4},
        {10, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}
    };

    int rows = array.size();
    int cols = array[0].size();

    int res = MaxSum(array, rows, cols);

    cout << res;
    return 0;
}