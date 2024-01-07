#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    string strmas[N];
    int mas[N][N];
    for (int i = 0; i < N; i++){
        cin >> strmas[i];
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            mas[i][j] = stoi(strmas[i].substr(j, 1));
        }
    }

    int Q;
    cin >> Q;
    int quest[Q][2];
    for (int i = 0; i < Q; i++){
        for (int j = 0; j < 2; j++){
            cin >> quest[i][j];
        }
    }

    for (int i = 0; i < Q; i++){
        if (mas[quest[i][0] - 1][quest[i][1] - 1] != 0){
            cout << 1 << endl << mas[quest[i][0] - 1][quest[i][1] - 1] << endl << endl;
        } else {
            vector<int> vec;
            vector<int> data;
            vector<int> finalvector;

            for (int j = 0; j < N; j++){
                data.push_back(j + 1);
                vec.push_back(mas[quest[i][0] - 1][j]);
            }
            for (int j = 0; j < N; j++){
                vec.push_back(mas[j][quest[i][1] - 1]);
            }

            sort(vec.begin(), vec.end());
            sort(data.begin(), data.end());
            set_difference(data.begin(), data.end(), vec.begin(), vec.end(), back_inserter(finalvector));
            
            (finalvector.size() != 0)? cout << finalvector.size() << endl: cout << 0;
            for (int j = 0; j< finalvector.size(); j++){
                cout << finalvector[j] << " ";
            }
            cout << endl << endl;
        }
    }
    return 0;
}