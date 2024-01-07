#include <iostream>
#include <stack>
#include <vector>
#include <utility>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    stack<int> st;
    vector<pair<int, int>> brackets;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            st.push(i + 1);
        } else if (s[i] == ')') {
            brackets.push_back(make_pair(st.top(), i + 1));
            st.pop();
        }
    }

    cout << brackets.size() << endl;
    for (auto p : brackets) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}

