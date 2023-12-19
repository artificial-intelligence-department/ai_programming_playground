#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    int q;
    int x, y;
    int placeOfAnalyse;
    vector<char> arr(100, 0);


    cin >> n;
    int elementsToChange = 0;


    for (int i = 0; i < (n * n); i++) {
        cin >> arr[i];
    }


    cin >> q;


    const int MAX_ITERATIONS = 100;
    const int REPLACEMENT_SIZE = 9;  


    int results[MAX_ITERATIONS];
    vector<vector<char>> replacements(MAX_ITERATIONS, vector<char>(REPLACEMENT_SIZE, 0)); 


    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        placeOfAnalyse = (x - 1) * n + y - 1;


        if (arr[placeOfAnalyse] != '0') {
            results[i] = 1;
            replacements[i][0] = arr[placeOfAnalyse];
            continue;
        }


        vector<char> lines = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};


        for (int u = 0; u < n; u++) {
            placeOfAnalyse = (x - 1) * n + u;


            for (int j = 0; j < n; j++) {
                if (arr[placeOfAnalyse] == lines[j]) {
                    lines[j] = 0;
                }
            }
        }


        for (int u = 0; u < n; u++) {
            placeOfAnalyse = u * n + (y - 1);


            for (int j = 0; j < n; j++) {
                if (arr[placeOfAnalyse] == lines[j]) {
                    lines[j] = 0;
                }
            }
        }


        elementsToChange = 0;  


        for (int h = 0; h < n; h++) {
            if (lines[h] != 0) {
                elementsToChange++;
            }
        }


        results[i] = elementsToChange;


        int k = 0;
        for (int j = 0; j < n && k < REPLACEMENT_SIZE; j++) {
            if (lines[j] != 0) {
                replacements[i][k++] = lines[j];
            }
        }
    }


    for (int i = 0; i < q; i++) {
        cout << results[i] << endl;
        for (int j = 0; j < results[i]; j++) {
            cout << replacements[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
