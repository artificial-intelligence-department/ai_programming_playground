#include <iostream>
#include <string>
#include <set>
using namespace std;

bool FUNC(int X, int Y, int element, string array1[], int N) {
    
    for (int i = 0; i < N; i++) {
        if (array1[X][i] - '0' == element || array1[i][Y] - '0' == element) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, Q, X, Y , counter = 0;

    cin >> N;

    string array[N];
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
    }

    cin >> Q;

    int desk_Q[Q][2];
    for (int i = 0; i < Q; ++i) 
    {
        for (int j = 0; j < 2; j++)
        {
            cin>>desk_Q[i][j];
        }
    }

    cout<<endl;

    for (int i = 0; i < Q; ++i) 
    {
        X = desk_Q[i][0];
        X--;
        Y = desk_Q[i][1];
        Y--;

        if (array[X][Y] != '0') 
        {
            cout << '1' << endl;
            cout << array[X][Y] << endl << endl;
            continue;
        }

        set<char> checker;

        for (int i2 = 1; i2 <= N; i2++) 
        {
            if (FUNC(X, Y, i2 , array, N)) 
            {
                checker.insert('0' + i2);
            }
        }

        counter = checker.size();

        cout << counter << endl;

        if (counter > 0) 
        {
            for (char i2 : checker) 
            {
                cout << i2<<"  ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
