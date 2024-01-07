#include <iostream>
#include <vector>
using namespace std;

vector<int> sort(vector<int>& name) {
    for (int i = 0; i < name.size(); i++) {
        for (int j = i + 1; j < name.size(); j++) {
            if (name[i] > name[j]) {
                // Swap elements if they are in the wrong order
                int temp = name[i];
                name[i] = name[j];
                name[j] = temp;
            }
        }
    }
    return name;
}
vector<int> rotate(vector<int>& arr, int K) {
    int N = arr.size();
    vector<int> rotatedArr(N);

    for (int i = 0; i < N; i++) {
        rotatedArr[(i + N - (K % N)) % N] = arr[i];
    }

    return rotatedArr;
}


int main (){

int N, K;

cin >> N;
cin >> K;

int arr[N];
vector<int> arrCopy;


for(int i = 0; i < N; i++){
    cin>>arr[i];
}

for (int i = 0; i < N; i++) {
        bool isDuplicate = false;

        for (int j = 0; j < arrCopy.size(); j++) {
            if (arr[i] == arrCopy[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            arrCopy.push_back(arr[i]);
        }
    }

    vector <int> arrUniqSort = sort(arrCopy);

    vector <int> result = rotate(arrUniqSort, K);
    cout << result.size() << endl;
 for (int i = 0; i < arrUniqSort.size(); i++) {
        cout << result[i] << " ";
    }


return 0;
}