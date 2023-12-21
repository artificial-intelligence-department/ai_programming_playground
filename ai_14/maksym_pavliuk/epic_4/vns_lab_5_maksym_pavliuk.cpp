#include<iostream>
using namespace std;
int count_one_col(int arr[4][4], int column){
    int sum;
    for(int i=0; i<4; i++){
        sum += arr[column][i];
    }
    return sum;
}

bool Is_There(int arr[4][4]){
    int curr_col=1,the_left_side_sum=0,the_right_side_sum=0;;
    bool answer=0;
    
    for(int i=0; i<2; i++){
        for(int i=0; i<curr_col; i++){
            the_left_side_sum = count_one_col(arr, i);
        
        }
        for(int i=0; i<3-curr_col; i++){
            the_right_side_sum = count_one_col(arr, i);
        }
        
        if(the_right_side_sum>the_left_side_sum){
            answer=1;
        }

        curr_col++;
    }
    
    return answer;
}

int main(){
    int a[4][4]={{1,2,3,4}, {2,2,2,2}, {0,0,1,0}, {5,1,0,1}};
    if(Is_There(a) == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}