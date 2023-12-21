#include <iostream>

using namespace std;

int signal(int signal, char type) {
    switch (type)
    {
    case 'k':
    return max(signal - 1, 0);
    break;

    case 'p':
    return (signal >= 1) ? 15 : 0;
    break;

    case 'z':
    return (signal >= 1) ? 0 : 15;
    break;
    }
    return 0;
}

int cabel(int n, const string& str) {
    int pow = 15;

    for (int i = 0; i < n; ++i) {
        pow = signal(pow, str[i]);
    }

    return pow;
}

int main() {
    
    int n;
    string str;

    cin >> n;

    cin >> str;

    
    int result = cabel(n, str);
    cout << result << endl;

    return 0;
}