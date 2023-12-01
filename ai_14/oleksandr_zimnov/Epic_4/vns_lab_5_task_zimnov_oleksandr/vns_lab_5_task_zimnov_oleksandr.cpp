#include <iostream>
#include <string>
using namespace std;
bool MyFunc(int** matrix, int rows, int columns){
    bool answer=true;
    int result;
    if(columns>1 && rows>1){
    for(int i=0; i<rows-1; i++){
        result=0;
        for(int j=0; j<columns; j++){
            result+=matrix[i][j]*matrix[i+1][j];
        }
        if(result!=0){
            answer=false;
            break;
        }
        result=0;
        for(int j=0; j<columns; j++){
            result+=matrix[i][j]*matrix[i][j];
        }
        if(result!=1){
            answer=false;
            break;
        }
    }
    }else{
        answer=false;
    }
    return answer;
}

int main()
{
    int rows, columns;
    cout<<"Enter rows of massive:"<<endl;
    cin>>rows;
    cout<<"Enter columns of massive:"<<endl;
    cin>>columns;
    cout<<"Enter number of massive: "<<endl;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
    if(MyFunc(matrix, rows, columns)==true)
    cout<<"Your matrix is orthonormal";
    else{
        cout<<"Your matrix isn't orthonormal";;
    }
    return 0;
}