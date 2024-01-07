#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

float average(vector<double> arr){
    double average = 0;
    for(int i = 0; i < arr.size(); i++){
        average += arr[i];
    }
    average /= arr.size();

    return average;
}

int main(){

    int size;
    cout << "Enter amount of numbers: ";
    cin >> size;

    vector<double> arr(size);
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    average(arr);
    cout << "Average  value: " << average(arr) << endl;

    auto min = min_element(arr.begin(), arr.end());
    cout << "Min value: " << *min << endl;

    auto max = max_element(arr.begin(), arr.end());
    cout <<  "Max Value: "<< *max << endl;



    return 0;
}