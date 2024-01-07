#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N, Q;
    cin >> N;

    vector<vector<int>> battlefield(N, vector<int>(N, 0));
    string text;

    for (int i = 0; i < N; i++) {
        cin >> text;
        for (int j = 0; j < N; j++) {
            battlefield[i][j] = text[j] - '0';
        }
    }

    cin >> Q;
    vector<vector<int>> asks(Q, vector<int>(2, 0));

    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> asks[i][j];
        }
    }

    vector<int> response;

    for (int i = 0; i < Q; i++) {
        int x = asks[i][0] - 1;
        int y = asks[i][1] - 1;

        int count = 1;
        for (int i = 0; i < N; i++) {
            response.push_back(count);
            count++;
        }

        if (battlefield[x][y] == 0) {
            for (int j = 0; j < N; j++) {
                if (battlefield[j][y] != 0) {
                    for (int k = 0; k < response.size(); k++) {
                        if (response[k] == battlefield[j][y]) {
                            response.erase(response.begin() + k);
                            k--;
                        }
                    }
                }

                if (battlefield[x][j] != 0) {
                    for (int k = 0; k < response.size(); k++) {
                        if (response[k] == battlefield[x][j]) {
                            response.erase(response.begin() + k);
                            k--;
                        }
                    }
                }
            }
        } else {
            vector<int> Answer;

            for (int j = 0; j < N; j++) {
                if (response[j] == battlefield[x][y]) {
                    Answer.push_back(response[j]);
                }
            }
            response = Answer;
        }

        cout << response.size() << endl;
        for (int k = 0; k < response.size(); k++) {
            cout << response[k] << " ";
        }
        cout << endl;
        response.clear();
    }

    return 0;
}
