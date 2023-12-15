#include <iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> arr1;
    vector<int> arr2;
    long int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        int value;
        cin >> value;
        arr1.push_back(value);
    }
    int count1 = 0;
    cin >> count1;
    for (int j = 0; j < count1; j++) {
        int value;
        cin >> value;
        arr2.push_back(value);
    }
    int nonunique = 0;
    for (int k = 0; k < count; k++)
    {
        for (int l = 0; l < count1; l++)
        {
            if(arr1[k] == arr2[l])
            {
                nonunique+=1;
            }
        }
    }
    cout <<nonunique<<endl<< count+count1-nonunique;
    return 0;
}