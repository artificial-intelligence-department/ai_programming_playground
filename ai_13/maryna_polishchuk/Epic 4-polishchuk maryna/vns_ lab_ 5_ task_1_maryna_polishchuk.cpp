#include <iostream>
#include <vector>
using namespace std;

bool CheckIfNumberOccurs(vector<int> arr, int num)
{
    /*тут треба написати код який будет як раз шукати*/
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == num)
            return true;
    }
    return false;
}

int main()
{
    int arr[3][3] = {
        {1,3,3}, 
        {5,6,7},
        {7,8,9}
        };
    cout << "Our array: " << endl ;
    //вивід вихідного масиву (для того щоб на простому показати як працювати з кожним ел-ом 2-го масиву)
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> temp, finalArray;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(CheckIfNumberOccurs(temp, arr[i][j]))
                finalArray.push_back(arr[i][j]);
            temp.push_back(arr[i][j]);
        }
    }
    cout << "Numbers that occure few times: ";
    for(int i = 0; i < finalArray.size(); i++){
        cout << finalArray[i] << " " ;}
        cout << endl;
        int max=finalArray[1];
    for (int i = 0; i < finalArray.size(); i++)
    {
        if(finalArray[i]>max){
            max=finalArray[i];
        }
        cout << "Max of numbers that occure few times:" << max;
    return 0;
}}