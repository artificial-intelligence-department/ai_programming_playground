#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int remainder0[N], remainder1[N], remainder2[N];
    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < N; ++i) {
        int remainder = arr[i] % 3;
        if (remainder == 0) {
            remainder0[count0++] = arr[i];
        } else if (remainder == 1) {
            remainder1[count1++] = arr[i];
        } else {
            remainder2[count2++] = arr[i];
        }
    }

    sort(remainder0, remainder0 + count0);

    sort(remainder1, remainder1 + count1, greater<int>());

    int result[N];
    copy(remainder0, remainder0 + count0, result);
    copy(remainder1, remainder1 + count1, result + count0);
    copy(remainder2, remainder2 + count2, result + count0 + count1);

    int M = 0;
    for (int i = 0; i < count0 + count1 + count2; ++i) {
        bool isDuplicate = false;
        for (int j = i + 1; j < count0 + count1 + count2; ++j) {
            if (result[i] == result[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            result[M++] = result[i];
        }
    }

    cout << M << endl;
    for (int i = 0; i < M; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}
