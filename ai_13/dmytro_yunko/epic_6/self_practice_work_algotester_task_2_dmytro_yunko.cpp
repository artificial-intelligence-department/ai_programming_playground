#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct G {
    int team;
    vector<int> neighbour;
};

void dfs(int start, vector<G>& teamAr) {
    stack<int> s;
    s.push(start);
    teamAr[start].team = 1;

    while (!s.empty()) {
        int v = s.top();
        s.pop();

        for (int u : teamAr[v].neighbour) {
            if (teamAr[u-1].team == 0) {
                s.push(u-1);
                teamAr[u-1].team = 3 - teamAr[v].team;
            } else if (teamAr[u-1].team == teamAr[v].team) {
                cout << "Impossible" << endl;
                exit(0);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    int friendsNum {0};
    int pairsNum {0};
    cin >> friendsNum >> pairsNum;

    vector<G> teamAr(friendsNum);

    for(size_t i=0;i<pairsNum;i++) {
        int a{0};
        int b{0};
        cin >>a >>b;
        teamAr[a-1].neighbour.push_back(b);
        teamAr[b-1].neighbour.push_back(a);
    }

    for (int i = 0; i < friendsNum; i++) {
        if (teamAr[i].team == 0) {
            dfs(i, teamAr);
        }
    }

    for(int i=0; i<friendsNum; i++)
        cout << teamAr[i].team;

    return 0;
}
