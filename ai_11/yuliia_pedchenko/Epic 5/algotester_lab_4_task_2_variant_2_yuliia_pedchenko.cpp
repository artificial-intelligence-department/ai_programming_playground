#include <iostream>
#include <vector>

using namespace std;

//////////////////////////////////////////////////////////////////

vector<int> bubblesort(vector<int> massive) {

    for (int i = 0; i < massive.size()-1; i++) {
        for (int j = 0; j < massive.size()-i-1; j++) {
            if (massive[j] > massive[j+1]) {
               swap(massive[j], massive[j+1]);

            }
        }
    }
    return massive;
}

//////////////////////////////////////////////////////////////////

vector<int> destroy(vector<int> massive) {

    for (int i = 1; i < massive.size()-1; i++) {
        if (massive[i] == massive[i-1] || massive[i] == massive[i+1]) {
            massive.erase(massive.begin()+i);
        i--;
        }
    }
    return massive;
}

//////////////////////////////////////////////////////////////////

vector<int> rotat(vector<int> massive, int K) {
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < massive.size()-1; j++) {
            swap(massive[j], massive[j+1]);
        }
    }
    return massive;
}

//////////////////////////////////////////////////////////////////

int main() {

    vector<int> a;
    int N, K;

    cin >> N >> K;
    if (N < 1 || K < 1 || N > 1000 || K > 1000) return 0;
    
    for (int i = 0; i < N; i++) {
        int ai;
        cin >> ai;
        if (ai < 0 || ai > 100) return 0;
        a.push_back(ai);
    }

    a = bubblesort(a);

    a = destroy(a);

    a = rotat(a, K);


    cout << a.size() << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }


    return 0;
}