#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Pair{
    int X;
    int Y;
};

vector<int> possibleValues(vector<vector<int>> game, int row, int col){
    int N = game.size();

    vector<int> possible;

    for (int value = 1; value <= N; ++value) {
        possible.push_back(value);
    }

    for (int j = 0; j < N; ++j) {
        auto it = find(possible.begin(), possible.end(), game[row][j]);
        if (it != possible.end()) {
            possible.erase(it);
        }
    }

    for (int i = 0; i < N; ++i) {
        auto it = find(possible.begin(), possible.end(), game[i][col]);
        if (it != possible.end()) {
            possible.erase(it);
        }
    }

    return possible;
}

int main(){
    int N;
    int Q;

    cin >> N;

    vector<vector<int>> game(N, vector<int>(N, 0));
    vector<int> num;
    vector<Pair> pairs;

    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        num.push_back(a);
    }

    cin >> Q;
    for(int i = 0; i < Q; i++){
        int x, y;
        cin >> x >> y;
        pairs.push_back({x, y});
    }

    for (int i = 0; i < num.size(); ++i) {
        int number = num[i];
        for (int j = N - 1; j >= 0; --j) {
            game[i][j] = number % 10;
            number /= 10;
        }
    }

    for(int i = 0; i < Q; i++){

        if(game[pairs[i].X - 1][pairs[i].Y - 1] != 0){
            cout << 1 << endl;
            cout << game[pairs[i].X - 1][pairs[i].Y - 1];
            cout << endl;
            cout << endl;
        }
        else{
            vector<int> possibleValuesVector = possibleValues(game, pairs[i].X - 1, pairs[i].Y - 1);
            
            cout << possibleValuesVector.size() << endl;

            for(int j = 0; j < possibleValuesVector.size(); j++){
                cout << possibleValuesVector[j] << " ";
            }
            cout << endl;
            cout << endl;
        }
    }
    return 0;
}