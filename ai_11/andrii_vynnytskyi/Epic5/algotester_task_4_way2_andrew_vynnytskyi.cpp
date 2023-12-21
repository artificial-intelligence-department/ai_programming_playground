#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int size;
    cin >> size;
    vector<int> numbers;
    for (int i = 0; i < size; i++){
        int number;
        cin >> number;
        numbers.push_back(number);
    }
    vector <int> buff0, buff1, buff2;
    for (int i = 0; i < size; i++){
        if (numbers[i] % 3 == 0){
            buff0.push_back(numbers[i]);
        }
        else if (numbers[i] % 3 == 1){
            buff1.push_back(numbers[i]);
        }
        else if (numbers[i] % 3 == 2){
            buff2.push_back(numbers[i]);
        }
    }

    sort(buff0.begin(),buff0.end());
    sort(buff1.begin(),buff1.end());
    reverse(buff1.begin(), buff1.end());
    sort(buff2.begin(),buff2.end());
    buff0.insert(buff0.end(), buff1.begin(), buff1.end());
    buff0.insert(buff0.end(), buff2.begin(), buff2.end());

   buff0.erase(unique(buff0.begin(), buff0.end()), buff0.end());

    cout<<buff0.size()<<endl;
    for(int i : buff0)
    {
        cout<<i<<' ';
    }

    return 0;
}