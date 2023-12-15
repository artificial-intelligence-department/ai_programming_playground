#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> N;
    vector<string> M;
    for (int i = 0; i < n; i++) {
        string H;
        cin >> H;
        N.push_back(H);
    }
    for (int i = 0; i < m; i++) {
        string H;
        cin >> H;
        M.push_back(H);
    }
    vector<string> rez;
    for (int i = 0; i < n; i++) {
        rez.push_back(N[i]);
    }
    for (int i = 0; i < m; i++) {
        rez.push_back(M[i]);
    }
    sort(rez.begin(), rez.end());
    rez.erase(unique(rez.begin(), rez.end()), rez.end());
    cout << rez.size();
    return 0;
}